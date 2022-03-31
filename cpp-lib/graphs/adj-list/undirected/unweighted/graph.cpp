#include<iostream>
#include<vector>
#include<bits/stdc++.h>

#define vt vector
#define ll long long

using namespace std;

template <typename T> bool vt_contains(vector<T> v, T e) {
   for (auto& c : v) {
      if (c == e) return true;
   }
   return false;
}

void print_graph(vt<vt<int>>& g) {
   cout << "--------------------------------------------------\n";
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
   cout << "ADJ-LIST, UNDIRECTED, UNWEIGHTED\n--------------------------------------------------\n";

   cout << "Please enter the number of vertices in the graph" << '\n';
   int n; cin >> n; 
   vt<vt<int>> adj(n);

   cout << "Please enter number of edges" << '\n';
   int m; cin >> m;

   for (int i = 0; i < m; i++) {
      cout << "Please enter edge #" << i + 1 << '\n';
      int u, v; cin >> u >> v;
      bool is_valid_edge = u < n && v < n && u >= 0 && v >= 0 && !vt_contains(adj[u], v) && !vt_contains(adj[v], u);
      if (!is_valid_edge) {
         cout << "Invalid edge!" << '\n';
         i--; continue;
      }
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   print_graph(adj);
   return 0;
}
