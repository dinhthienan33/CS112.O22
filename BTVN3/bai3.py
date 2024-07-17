from bisect import bisect_left

def solve(arr):
    dp = []
    index = []
    prev = [None] * len(arr)

    for i, x in enumerate(arr):
        j = bisect_left(dp, x)
        if j == len(dp):
            dp.append(x)
            index.append(i)
        else:
            dp[j] = x
            index[j] = i
        if j > 0:
            prev[index[j]] = index[j-1]
    res = []
    i = index[-1]
    while i is not None:
        res.append(arr[i])
        i = prev[i]
    res.reverse()

    return len(res), res

n = int(input())
arr = list(map(int, input().split()))
length, res = solve(arr)
print(length)
print(' '.join(map(str, res)))