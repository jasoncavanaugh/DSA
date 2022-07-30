#include<iostream>
#include<utility>//std::pair, std::make_pair
#include<vector>
#include<bits/stdc++.h>
#include<limits>

using namespace std;

#define vt vector
#define ll long long
#define pr pair
#define mkpr make_pair

using namespace std;


/* 
 *
 * Adjacency list is stored as a vector<vector<pair<int, int>>>
 * pair.first is the vertex number of the neighbor
 * pair.second is the weight of the edge to the neighbor
 *
 * When entering edges, the format is vertex, weight, vertex
 *
 * The output is
 *
 * Vertex #i: weight_1, neighbor_1; ...... ; weight_m, neighbor_m
 *
 */

bool vt_contains(vector<pr<int, int>> v, int e) {
   for (auto& c : v) {
      if (c.first == e) return true;
   }
   return false;
}


void print_graph(vt< vt< pr<int, int> > >& g) {
   cout << "--------------------------------------------------\n";
   int n = g.size();
   for (int i = 0; i < n; i++) {
      sort(g[i].begin(), g[i].end(), [](pr<int, int> a, pr<int, int> b) -> bool { return a.first - b.first });
      int s = g[i].size();
      cout << "Vertex " << i << ": ";
      for (int j = 0; j < s; j++) {
         cout << g[i][j].second << ", " << g[i][j].first << "; ";
      }
      cout << '\n';
   }
}

int main() {
   cout << "ADJ-LIST, UNDIRECTED, WEIGHTED\n--------------------------------------------------\n";
   
   cout << "Please enter the number of vertices in the graph" << '\n';
   int n; cin >> n; 

   cout << "Please enter number of edges" << '\n';
   int m; cin >> m;

   vt< vt < pr<int, int> > > adj(n);

   for (int i = 0; i < m; i++) {
      cout << "Please enter edge #" << i + 1 << '\n';

      int u, w, v; cin >> u >> w >> v;

      bool is_valid_edge = u < n && v < n && u >= 0 && v >= 0 && !vt_contains(adj[u], v) && !vt_contains(adj[v], u);
      if (!is_valid_edge) {
         cout << "Invalid edge!" << '\n';
         i--; continue;
      }

      adj[u].push_back(mkpr(v, w));
      adj[v].push_back(mkpr(u, w));
   }

   print_graph(adj);

   return 0;
}

