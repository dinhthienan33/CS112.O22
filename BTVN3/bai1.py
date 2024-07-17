n, q = map(int, input().split())
arr = list(map(int, input().split()))
for i in range(1, n):
    arr[i] = arr[i-1] + arr[i]
for _ in range(q):
    first, last = map(int, input().split())
    if first > 1:
        print(arr[last-1] - arr[first-2])
    else:
        print(arr[last-1])