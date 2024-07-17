def solve():
    S = int(input())
    dp = [0] * (S + 7)
    dp[0] = 1
    number = pow(10,9)+7
    for i in range(1, S + 1):
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % number
    print(dp[S])
solve()