from typing import *
import heapq

def dijkstras(graph: List[List[Tuple[int, int]]], start: int, end: int):
    heap = []
    heapq.heapify(heap)

    n = len(graph)
    visited = [False for i in range(n)]
    dist = [float("inf") for i in range(n)]
    parents = [-1 for i in range(n)]
    dist[start] = 0
    heapq.heappush(heap, (dist[start], 0))
    while len(heap) > 0:
        (_, cur_vertex) = heapq.heappop(heap)
        visited[cur_vertex] = True
        for (neighbor, weight) in graph[cur_vertex]:
            if not visited[neighbor] and dist[cur_vertex] + weight < dist[neighbor]:
                dist[neighbor] = dist[cur_vertex] + weight
                parents[neighbor] = cur_vertex
                heapq.heappush(heap, (dist[neighbor], neighbor))

    path = []
    cur = e
    while cur != -1:
        path.append(cur)
        cur = parents[cur]

    return list(reversed(path))

graph = [[(1, 5), (2, 3)], [(0, 5), (2, 1), (3, 2)], [(1, 1), (0, 3), (4, 7)], [(1, 2), (4, 10)], [(2, 7), (3, 10)]]

points = [[0, 3], [0, 4]]
for s, e in points:
    print(s, e, ":", dijkstras(graph, s, e))
