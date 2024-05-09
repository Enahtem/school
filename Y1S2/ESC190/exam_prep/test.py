import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    priority_queue = [(0, start)]

    while priority_queue:
        dist, node = heapq.heappop(priority_queue)

        # If the current distance is greater than what's already stored, skip
        if dist > distances[node]:
            continue

        # Iterate through neighbors of the current node
        for neighbor, weight in graph[node].items():
            new_dist = dist + weight
            # If the new distance is shorter than the known distance, update
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(priority_queue, (new_dist, neighbor))

    return distances

graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

print(dijkstra(graph, 'A'))
