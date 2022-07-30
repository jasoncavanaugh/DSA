from typing import List, Tuple

class MinHeap:
    def __init__(self):
        self.arr = []
        self.vertex_to_idx = {}

    def is_empty(self) -> bool:
        return len(self.arr) == 0
    
    def add(self, element: Tuple[int, int]):
        self.arr.append(element)
        (vertex, _) = element
        self.vertex_to_idx[vertex] = len(self.arr) - 1
        self._swim(len(self.arr) - 1)

    def pop_top(self, element: Tuple[int, int]):
        self._swap(0, len(self.arr) - 1)

        removed_element = self.arr.pop()
        (removed_vertex, _) = removed_element
        self.vertex_to_idx.pop(removed_vertex)

        (vertex, _) = self.arr[0]
        self.vertex_to_idx[vertex] = 0
        self._sink(0)
        return removed_element

    def update(self, vertex: int, new_dist: int):
        idx = self.vertex_to_idx[vertex]
        self.arr[idx] = (vertex, new_dist)
        self._swim(idx)

    # Private methods
    def _sink(self, idx: int):
        if not self._is_valid_idx(idx):
            return

        min_idx = idx

        left_idx = 2*idx + 1
        if left_idx < len(self.arr) and self.arr[left_idx][1] < self.arr[min_idx][1]:
            min_idx = left_idx

        right_idx = 2*idx + 2
        if right_idx < len(self.arr) and self.arr[right_idx][1] < self.arr[min_idx][1]:
            min_idx = right_idx

        if min_idx != idx:
            # swap
            self._swap(min_idx, idx)
            self._sink(min_idx)


    def _swim(self, idx: int):
        parent_idx = (idx - 1)//2
        if not self._is_valid_idx(idx) or not self._is_valid_idx(parent_idx):
            return


        (_, dist) = self.arr[idx]
        (_, parent_dist) = self.arr[parent_idx]
        if dist < parent_dist:
            self._swap(parent_idx, idx)
            self._swim(parent_idx)

    def _swap(a: int, b: int):
        if not _is_valid_idx(a):
            raise ValueError(f"Invalid index {a}")

        if not _is_valid_idx(b): 
            raise ValueError(f"Invalid index {b}")

        # swap
        temp = self.arr[a]
        self.arr[a] = self.arr[b]
        self.arr[b] = temp

        # update vertex_to_idx
        (vertex_a, _) = self.arr[a]
        self.vertex_to_idx[vertex_a] = a
        (vertex_b, _) = self.arr[b]
        self.vertex_to_idx[vertex_b] = b


    # Validation
    def _is_valid_idx(self, idx: int) -> bool:
        return idx >= 0 and idx < len(self.arr)


# graph -> adj list of (vertex, weight)
def dijkstras(graph: List[List[int]], start: int):
    n = len(graph)
    dist = [float("inf") for i in range(n)]
    dist[start] = 0
    pq = MinHeap()
    pq.add((start, dist[start]))

    while not pq.is_empty():
        cur = pq.pop_top()
        for (neigh, weight) in graph[cur]:
            if weight + dist[cur] < dist[neigh]:
                dist[neigh] = weight + dist[cur]
                pq.update(neigh, dist[neigh])

    return dist

