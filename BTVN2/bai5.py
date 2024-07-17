def main():
    v, e, n = map(int, input().split())
    vertices = input().split()
    graph = {vertex: [] for vertex in vertices}
    for _ in range(e):
        u, i = map(str, input().split())
        graph[u].append(i)
        graph[i].append(u)
    colors = list(map(int, input().split()))
    color_map = {vertex: -1 for vertex in vertices}
    used_colors = set()
    for vertex, color in zip(vertices, colors):
        color_map[vertex] = color
        if color != -1:
            used_colors.add(color)
    ques = input().split()
    for i in ques:
        if color_map[i] != -1 and all(color_map[j] != color_map[i] for j in graph[i]):
            print("TRUE")
        else:
            for color in sorted(used_colors):
                if all(color_map[j] != color for j in graph[i]):
                    color_map[i] = color
                    print(color)
                    break
            else:
                new_color = 0
                while new_color in used_colors:
                    new_color += 1
                color_map[i] = new_color
                used_colors.add(new_color)
                print(new_color)

if __name__ == "__main__":
    main()