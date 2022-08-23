from Typing import *

def dfs_recursive_helper(adj_lst: List[List[int]], vertex: int, visited: List[List[int]]):
    if visited[vertex]:
        return
    visited[vertex] = True
    for neighbor in adj_lst[vertex]:
        dfs_recursive_helper(adj_lst, neighbor, visited)

def dfs_recursive(adj_lst: List[List[int]], start_vertex: int):
    visited = [False for i in range(len(adj_lst))]
    dfs_recursive_helper(adj_lst, start_vertex, visited)


def dfs_iterative(adj_lst: List[List[int]], start_vertex: int):
    stack = []
    visited = [False for i in range(len(adj_lst))]
    visited[start_vertex] = True
    stack.append(start_vertex)
    while len(stack) > 0:
        cur_vertex = stack.pop()
        for neighbor in adj_lst[cur_vertex]:
            if visited[neighbor]:
                continue
            visited[neighbor] = True
            stack.append(neighbor)
