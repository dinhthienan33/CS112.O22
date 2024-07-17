class Item:
    def __init__(self, weight: int, value: int):
        self.weight = weight
        self.value = value

def solve() -> None:
    n, x = map(int, input().split())
    items = [Item(*map(int, input().split())) for _ in range(n)]
    dp = [0 for _ in range(x + 1)]
    for i in range(n):
        for j in range(x, 0, -1):
            if items[i].weight <= j:
                dp[j] = max(dp[j], dp[j-items[i].weight] + items[i].value)

    print(dp[x])

if __name__ == "__main__":
    solve()