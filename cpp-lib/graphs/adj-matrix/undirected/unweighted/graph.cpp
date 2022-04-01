#include<iostream>
#include<vector>
#include<bits/stdc++.h>

#define vt vector
#define ll long long

using namespace std;

void print_graph(vt<vt<int>>& g) {
   cout << "--------------------------------------------------\n";

   int n = g.size();
   cout << "__| ";
   for (int i = 0; i < n; i++) {
      cout << i << " | ";
   }
   cout << '\n';

   for (int i = 0; i < n; i++) {
      cout << i << " | ";
      for (int j = 0; j < n; j++) {
         if (g[i][j]) {
              cout << g[i][j];
         } else {
            cout << " ";
         }
         cout  << " | ";
      }
      cout << '\n';
   }
}

int main() {
   cout << "ADJ-MATRIX, UNDIRECTED, UNWEIGHTED\n--------------------------------------------------\n";

   cout << "Please enter the number of vertices in the graph" << '\n';

   int n; cin >> n; 
   vt<vt<int>> adj(n, vt<int>(n));

   cout << "Please enter number of edges" << '\n';
   int m; cin >> m;

   for (int i = 0; i < m; i++) {
      cout << "Please enter edge #" << i + 1 << '\n';
      int u, v; cin >> u >> v;
      bool is_valid_edge = u < n && v < n && u >= 0 && v >= 0 && adj[u][v] != 1 && adj[v][u] != 1;
      if (!is_valid_edge) {
         cout << "Invalid edge!" << '\n';
         i--; continue;
      }
      adj[u][v] = 1;
      adj[v][u] = 1;
   }

   print_graph(adj);

   return 0;
}
