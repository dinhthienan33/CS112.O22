import heapq

def a_star(graph, start, goal, heuristic):
    open_list = []
    heapq.heappush(open_list, (0, start))
    parent = {start: None}
    g_score = {start: 0}
    f_score = {start: heuristic[start]}
    expanded_nodes = 0
    while open_list:
        _, current = heapq.heappop(open_list)
        expanded_nodes += 1
        if current == goal:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            path.reverse()
            return path,expanded_nodes
        for neighbor in graph[current]:
            if neighbor not in g_score or g_score[current] + graph[current][neighbor] < g_score[neighbor]:
                parent[neighbor] = current
                g_score[neighbor] = g_score[current] + graph[current][neighbor]
                f_score[neighbor] = g_score[current] + graph[current][neighbor] + heuristic[neighbor]
                heapq.heappush(open_list, (f_score[neighbor], neighbor))

    return None, expanded_nodes
def main():
    v, e = map(int, input().split())
    start, goal = input().split()
    vertices = input().split()
    heuristic = dict(zip(vertices, map(int, input().split())))
    graph = {vertex: {} for vertex in vertices}

    for _ in range(e):
        v, w, x = input().split()
        x = int(x)
        graph[v][w] = x

    path, expanded_nodes = a_star(graph, start, goal, heuristic)

    if path is None:
        print("-unreachable-")
        print(f"{expanded_nodes} 0")
    else:
        print(" ".join(path))
        print(f"{expanded_nodes} {sum(graph[path[i]][path[i+1]] for i in range(len(path)-1))}")
if __name__ == '__main__':
    main()