class Building:
    def __init__(self, left, right, height):
        self.left = left
        self.right = right
        self.height = height

def skyline(buildings):
    max_right = max(building.right for building in buildings)

    skyline_heights = [0] * (max_right + 1)

    for building in buildings:
        for x in range(building.left, building.right):
            skyline_heights[x] = max(skyline_heights[x], building.height)

    critical_points = []
    prev_height = 0
    for x, height in enumerate(skyline_heights):
        if height != prev_height:
            critical_points.append((x, height))
            prev_height = height

    return critical_points

def main():
    num_buildings = int(input())
    buildings_list = []
    for _ in range(num_buildings):
        left, right, height = map(int, input().split())
        buildings_list.append(Building(left, right, height))

    critical_points = skyline(buildings_list)

    for x, height in critical_points:
        print(f"{x} {height}")

if __name__ == "__main__":
    main()