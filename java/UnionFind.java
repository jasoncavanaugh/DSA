import java.utils.*;

class UnionFind {
  private int[] parents, sizes;
  public UnionFind(int n) {
    parents = new int[n];
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    for (int i = 0; i < n; i++) {
      sizes[i] = 1;
    }
  }

  public int find(int a) {
    int cur = a;
    while (cur != parents[cur]) {
      cur = parents[cur];
    }
    int root = cur;
    cur = a;
    while (cur != parents[cur]) {
      int next = parents[cur];
      parents[cur] = root;
      cur = parents[cur];
    }
    return root;
  }

  public void union(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a == root_b) return;
    int bigger = sizes[root_a] >= sizes[root_b] ? root_a : root_b;
    int smaller = sizes[root_a] < sizes[root_b] ? root_a : root_b;
    sizes[bigger] += sizes[smaller];
    parents[smaller] = parents[bigger];
  }
}
