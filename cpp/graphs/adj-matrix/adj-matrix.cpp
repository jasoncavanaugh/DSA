#include<iostream>
#include<vector>
#include<string>
#include<set>
#include <bits/stdc++.h>

#define vt vector
#define ll long long

using namespace std;

void print_graph(vt<vt<int>>& g) {
   int n = g.size();
   for (int i = 0; i < n; i++) {
      sort(g[i].begin(), g[i].end());
      int s = g[i].size();
      cout << "Vertex " << i << ": ";
      for (int j = 0; j < s; j++) {
         cout << g[i][j] << ", ";
      }
      cout << '\n';
   }
}

int main() {
   cout << "Is this an undirected graph?" << '\n';
   bool is_undirected; cin >> is_undirected;
   cout << "Please enter the number of vertices in the graph" << '\n';
   int n; cin >> n; 
   vt<vt<int>> adj(n, vt<int>(n));
   cout << "Please enter number of edges" << '\n';
   int m; cin >> m;
   for (int i = 0; i < m; i++) {
      cout << "Please enter edge #" << i + 1 << '\n';
      int u, v; cin >> u >> v;
      if (u >= n || v >= n || u < 0 || v < 0 || adj[v][u] ==  || vt_contains(adj[v], u)) {
         cout << "Invalid edge!" << '\n';
         i--; continue;
      }
      adj[u][v] = 1;
      if (is_undirected) {
         adj[v][u] = 1;
      }
   }
   print_graph(adj);
   return 0;
}
