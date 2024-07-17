from queue import PriorityQueue

def solve():
    v, n = map(int, input().split())
    name_map = {}
    idx_map = [""] * v
    s = input().strip()
    vertices=input().split()
    for i in range(v):
        name_map[vertices[i]] = i
        idx_map[i] = vertices[i]
    adj = [list(map(int, input().split())) for _ in range(v)]
    d = [(float('inf'), None) for _ in range(v)]
    d[name_map[s]] = (0, None)
    Q = PriorityQueue()
    Q.put((0, name_map[s]))
    opened_node = 0
    while not Q.empty():
        u = Q.get()[1]
        if idx_map[u] == s:
            it = u
            while it is not None:
                print(idx_map[it], end=" ")
                it = d[it][1]
            print()
            opened_node += 1
            print(opened_node, d[u][0])
            return
        opened_node += 1
        for j in range(v):
            if adj[u][j] and d[j][0] > d[u][0] + adj[u][j]:
                d[j] = (d[u][0] + adj[u][j], u)
                Q.put((d[j][0], j))
    print("-unreachable-")
    print(opened_node, 0)
solve()