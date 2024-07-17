
def solve(graph, V):
    dist = [[float('inf')] * V for _ in range(V)]
    for node in range(V):
        dist[node][node] = 0
    for u in graph:
        for v in graph[u]:
            dist[u-1][v-1] = 1
            dist[v-1][u-1] = 1
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist

def main():
    n, q = map(int, input().split())
    graph = {}

    for _ in range(n - 1):
        a, b = map(int, input().split())
        if a not in graph:
            graph[a] = []
        if b not in graph:
            graph[b] = []
        graph[a].append(b)
        graph[b].append(a)

    dist = solve(graph, n)

    for _ in range(q):
        a, b = map(int, input().split())
        print(dist[a-1][b-1])

if __name__ == "__main__":
    main()