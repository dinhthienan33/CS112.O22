def main():
    v, e = map(int, input().split())
    vertices = input().split()
    graph = {vertex: [] for vertex in vertices}
    for _ in range(e):
        u, i = map(str, input().split())
        graph[u].append(i)
        graph[i].append(u)
    print(' '.join(str(len(graph[v])) for v in graph))
if __name__ == "__main__":
    main()