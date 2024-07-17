def solve(balloons):
    n = len(balloons)
    dp = [[0]*n for _ in range(n)]
    for length in range(n):
        for left in range(n - length):
            right = left + length
            for k in range(left, right + 1):
                left_value = 1 if left - 1 < 0 else balloons[left - 1]
                right_value = 1 if right + 1 == n else balloons[right + 1]
                before = 0 if k - 1 < left else dp[left][k - 1]
                after = 0 if k + 1 > right else dp[k + 1][right]
                dp[left][right] = max(dp[left][right], before + after + left_value * balloons[k] * right_value)
    return dp[0][n - 1]

n = int(input().strip())
balloons = [int(input().strip()) for _ in range(n)]
print(solve(balloons))