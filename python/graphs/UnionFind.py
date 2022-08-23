class UnionFind:
    def __init__(self, size: int):
        self.parents = [i for i in range(size)]
        self.sizes = [1 for i in range(size)]

    def union(self, v: int, u: int):
        v = find(v)
        u = find(u)
        if find(v) == find(u): 
            return

        if self.sizes[v] > self.size[u]:
            self.parents[u] = self.parents[v]
            self.sizes[u] += self.sizes[v]
            self.sizes[v] = self.sizes[u]
        else:
            self.parents[v] = self.parents[u]
            self.sizes[v] += self.sizes[u]
            self.sizes[u] = self.sizes[v]

    def find(self, v: int):
        cur = v
        while cur != self.parents[cur]:
            cur = self.parents[cur]

        root = cur
        # Path compression
        cur = v
        while cur != self.parents[cur]:
            par = self.parents[cur]
            self.parents[cur] = root
            cur = par

        return root
