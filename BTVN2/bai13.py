import heapq
import math

def get_legal_actions(layout, pos):
    legal_actions = []
    actions = [(1, 1), (1, 0), (-1, 1), (-1, 0), (1, -1), (0, 1), (-1, -1), (0, -1)]
    for action in actions:
        if 0 <= pos[0] + action[0] < len(layout) and 0 <= pos[1] + action[1] < len(layout[0]) and not layout[pos[0] + action[0]][pos[1] + action[1]]:
            legal_actions.append((pos[0] + action[0], pos[1] + action[1]))
    return legal_actions

def heuristic(a, b):
    return float(math.sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2))

def a_star(grid, start, goal):
    m, n = len(grid), len(grid[0])
    open_list = [(0, start)]
    g_score = {start: 0}
    f_score = {start: heuristic(start, goal)}
    while open_list:
        _, current = heapq.heappop(open_list)
        if current == goal:
            return g_score[current]
        legal_action = get_legal_actions(grid, current)
        for neighbor in legal_action:
            tentative_g_score = g_score[current]+1
            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = 2*(g_score[neighbor]+1) + heuristic(neighbor, goal)
                heapq.heappush(open_list, (f_score[neighbor], neighbor))
    return -1

def main():
    m, n, sx, sy, gx, gy = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(m)]
    print(a_star(grid, (sx, sy), (gx, gy)))

main()