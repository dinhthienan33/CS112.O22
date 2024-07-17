def solve(n, x, price, pages):
    dp = [0] * (x + 1)
    for i in range(n):
        for j in range(x, pages[i]-1, -1):
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i])
    print(dp)
    return dp[x]

n, x = map(int, input().split())
price = list(map(int, input().split()))
pages = list(map(int, input().split()))
print(solve(n, x, price, pages))