#include <bits/stdc++.h>

#define ll long long
#define pr pair
#define vt vector
#define mkpr_make_pair

using namespace std;

class UnionFind {
  public:
    UnionFind(int n) {
      parents(n);
      for (int v : parents) {
        cout << v << ", ";
      }
      cout << '\n';
    }
  vt<int> parents;
};

int main() {
  UnionFind uf(10);


  return 0;
}
