def bfs(graph, start):
    visited = set()
    queue = [start]
    while len(queue)>0:
        vertex = queue.pop(0)
        if vertex not in visited:
            print(vertex, end=" ")
            visited.add(vertex)
            queue.extend([neighbour for neighbour in graph[vertex] if neighbour not in visited])

def dfs(graph, start):
    visited = set()
    stack = [start]
    while len(stack)>0:
        vertex = stack.pop()
        if vertex not in visited:
            print(vertex, end=" ")
            visited.add(vertex)
            stack.extend([neighbour for neighbour in graph[vertex] if neighbour not in visited])

adjacency_graph = {
    '1': ['3', '6'],
    '2': ['3', '5'],
    '3': ['1', '2', '4', '5'],
    '4': ['3', '5'],
    '5': ['2', '3', '4', '6'],
    '6': ['1', '5']
}

print("BFS:")
bfs(adjacency_graph, '1')
print("\n")

print("DFS:")
dfs(adjacency_graph, '1')
