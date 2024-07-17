def input_graph():
    v, n = map(int, input().split())
    vertices = input().split()
    graph = {vertex: {} for vertex in vertices}
    for i in range(v):
        edges = list(map(int, input().split()))
        for j in range(v):
            if edges[j] != 0:
                graph[vertices[i]][vertices[j]] = edges[j]
            else:
                graph[vertices[i]][vertices[j]] = float('inf')
    queries = [input().split() for _ in range(n)]
    return graph, queries
def dijkstra(graph, start, end):
    open = [(0, start)]
    close = set()
    distance = {vertex: float('inf') for vertex in graph}
    parent = {vertex: None for vertex in graph}
    distance[start] = 0
    while open:
        min_dist, _ = min(open, key=lambda x: x[0])  
        last_min_index = max(i for i, (dist, _) in enumerate(open) if dist == min_dist)
        dist, current = open.pop(last_min_index) 
        if(current in close):
            continue
        close.add(current)
        if current == end:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            path.reverse()
            return distance[end], len(close), path
        for neighbor, cost in graph[current].items():
            old_cost = distance[neighbor]
            new_cost = dist + cost
            if new_cost < old_cost:
                distance[neighbor] = new_cost
                parent[neighbor] = current
                open.append((new_cost, neighbor))
    return float('inf'), len(close), []
def main():
    graph, queries = input_graph()
    for start, end in queries:
        length, expanded ,path= dijkstra(graph, start, end)
        if length == float('inf'):
            print('-unreachable-')
            print(f'{expanded} {0}')
        else:
            print(" ".join(str(node) for node in path))
            print(f'{expanded} {length}')
if __name__ == "__main__":
    main()