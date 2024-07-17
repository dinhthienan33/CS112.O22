def main():
    v, e = map(int, input().split())
    vertices = input().split()
    graph = {vertex: [] for vertex in vertices}
    for _ in range(e):
        u, i = map(str, input().split())
        graph[u].append(i)
        graph[i].append(u)
    color_map = {vertex: -1 for vertex in vertices}
    used_colors = set()
    ans = []

    # Sort vertices based on their degree
    vertices_sorted = sorted(vertices, key=lambda x: len(graph[x]))

    for i in vertices_sorted:
        for color in sorted(used_colors):
            if all(color_map[j] != color for j in graph[i]):
                color_map[i] = color
                ans.append(color)
                break
        else:
            new_color = 0
            used_colors_sorted = sorted(used_colors)
            while new_color in used_colors_sorted:
                new_color += 1
            color_map[i] = new_color
            used_colors.add(new_color)
            ans.append(new_color)
    print(' '.join(str(i) for i in ans))

if __name__ == "__main__":
    main()