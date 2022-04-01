#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<limits>

#define vt vector
#define ll long long

using namespace std;

void print_graph(vt<vt<int>>& g) {
   cout << "--------------------------------------------------\n";

   int n = g.size();
   cout << "__|  ";
   for (int i = 0; i < n; i++) {
      cout << i << " |  ";
   }
   cout << '\n';

   for (int i = 0; i < n; i++) {
      cout << i << " | ";
      for (int j = 0; j < n; j++) {
         if (g[i][j] != INT_MAX) {
            if (g[i][j] < 0) {
              cout << g[i][j] << " | ";
            } else {
              cout << " " << g[i][j] << " | ";
            }
         } else {
            cout << "   | ";
         }
      }
      cout << '\n';
   }
}

int main() {
   cout << "ADJ-MATRIX, UNDIRECTED, WEIGHTED\n--------------------------------------------------\n";

   cout << "Please enter the number of vertices in the graph" << '\n';

   int n; cin >> n; 
   vt<vt<int>> adj(n, vt<int>(n));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         adj[i][j] = INT_MAX;
      }
   }

   cout << "Please enter number of edges" << '\n';
   int m; cin >> m;

   for (int i = 0; i < m; i++) {
      cout << "Please enter edge #" << i + 1 << '\n';
      int u, w, v; cin >> u >> w >> v;
      bool is_valid_edge = u < n && v < n && u >= 0 && v >= 0 && adj[u][v] == INT_MAX && adj[v][u] == INT_MAX;
      if (!is_valid_edge) {
         cout << "Invalid edge!" << '\n';
         i--; continue;
      }
      adj[u][v] = w;
      adj[v][u] = w;
   }

   print_graph(adj);

   return 0;
}
