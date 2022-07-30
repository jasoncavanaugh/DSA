#include <bits/stdc++.h>

#define ll long long
#define pr pair
#define vt vector
#define mkpr_make_pair

using namespace std;

class UnionFind {
  private:
    vt<int> parents;
    vt<int> sizes; 

  public:
    UnionFind(int n): parents(n), sizes(n) {
      for (int i = 0; i < n; i++) {
        parents[i] = i;
        sizes[i] = 1;
      }
    }

    int find(int a) {
      int cur = a;
      while (parents[cur] != cur) {
        cur = parents[cur];
      }
      int root = cur;
      cur = a;
      
      //path compression
      while (parents[cur] != root) {
        int next = parents[cur];
        parents[cur] = root;
        sizes[cur] = sizes[root];
        cur = next;
      }
      return root;
    }

    void unionize(int a, int b) {
      int root_a = find(a); 
      int root_b = find(b);
      if (root_a == root_b) return;
      int bigger = sizes[root_a] >= sizes[root_b] ? root_a : root_b;
      int smaller = sizes[root_a] < sizes[root_b] ? root_a : root_b;
      sizes[bigger] += sizes[smaller];
      parents[smaller] = parents[bigger];
    }

    void _inspect() {
      //print elements
      for (int i = 0; i < parents.size(); i++) {
        cout << i << " ";
      }
      cout << '\n';

      //print parents
      for (int i = 0; i < parents.size(); i++) {
        cout << parents[i] << " ";
      }
      cout << '\n';
          
      //print sizes
      for (int i = 0; i < sizes.size(); i++) {
        cout << sizes[i] << " ";
      }
      cout << '\n';
    }
};

int main() {
  cout << "Enter the number of elements" << '\n';
  int n; cin >> n;
  UnionFind uf(n);
  while (true) {
    uf._inspect();
    cout << "Enter two numbers to union." << '\n';
    int a, b; cin >> a >> b;
    if (a >= n || b >= n) {
      cout << "Invalid input!" << '\n';
      continue;
    }
    uf.unionize(a,b);
  }
  return 0;
}
