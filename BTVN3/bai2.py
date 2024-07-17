from bisect import bisect_left
def solve(arr):
    dp = []
    for x in arr:
        i = bisect_left(dp, x)
        if i == len(dp):
            dp.append(x)
        else:
            dp[i] = x
    return len(dp),dp

n = int(input())
arr = list(map(int, input().split()))
print(solve(arr))
