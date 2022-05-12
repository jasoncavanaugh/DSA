#include <bits/stdc++.h> 

#define vt vector
#define pr pair
#define mkpr make_pair
#define ll long long

using namespace std;

bool vt_contains(vt<pr<int, int>> 
vt<int> get_indeg(vt<vt<pr<int, int>>>& adj) {
   int n = adj.size(); 
   vt<int> indeg(n);
   for (int i = 0; i < n; i++) {
      int s = adj[i].size();
      for (int j = 0; j < s; j++) {
         int neighbor = adj[i][j].second;
         indeg[neighbor]++;
      }
   }
   return indeg;
}

bool is_valid_flow_network(vt<vt<pr<int, int>>>& adj) {
   vt<int> indeg = get_indeg(adj);

   bool exists_possible_source = false;
   bool exists_possible_sink = false;
   for (int i = 0; i < n; i++) {
      if (indeg[i] == 0) exists_possible_source = true;
      if (adj[i].size() == 0) exists_possible_sink = true;
   }
   return exists_possible_source && exists_possible_sink;
}

int get_source(vt<vt<pr<int,int>>>& adj) {
   vt<int> indeg = get_indeg(adj);

   int source;
   for (bool is_valid_source = false; !is_valid_source; ) {
      cout << "Enter the source vertex" << '\n';
      cin >> source;
      is_valid_source = source >= 0 && source < n && indeg[source] == 0;
      if (!is_valid_source) {
         cout << "Invalid source vertex!" << '\n';
      }
   }
   return source;
}

int get_sink(vt<vt<pr<int,int>>>& adj) {
   vt<int> indeg = get_indeg(adj);

   int sink;
   for (bool is_valid_sink = false; !is_valid_sink; ) {
      cout << "Enter the sink vertex" << '\n';
      cin >> sink;
      is_valid_sink = sink < 0 || sink >= n || indeg[sink] != 0;
      if (!is_valid_sink) {
         cout << "Invalid sink vertex!" << '\n';
      }
   }
   return sink;
}

int main() {
   cout << "Ford-Fulkerson Algorithm\n--------------------------------------------------\n";
  
   //Read 
   cout << "Enter the number of vertices in your flow network" << '\n';
   int n; cin >> n;
   cout << "Enter the number of edges in your flow network" << '\n';
   int m; cin >> m;
   vt<vt<edge>> adj(n);
   for (int i = 0; i < n; i++) {
      cout << "Enter edge number " << i + 1 << " (edge, capacity, edge): ";
      int u, w, v; cin >> u >> w >> v;
      bool is_valid = u >= 0 && u < n && v >= 0 && v < n && w >= 0 && !vt_contains(adj[u], v);
      if (!is_valid) {
         cout << "Invalid edge!" << '\n';
         i--; continue;
      }
      adj[u].push_back(mkpr(w, v));
   }
   
   //Check that there are possible sources and sinks
   if (!is_valid_flow_network(adj)) {
      cout << "Yo man this is not a valid flow network!" << '\n';
      return 1;
   }
   //Read source
   int source = get_source(adj);
   //Read sink
   int source = get_sink(adj);

   //Ford-Fulkerson



   return 0;
}
