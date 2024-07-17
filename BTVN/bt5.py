import math

count = 0

def round_to_tenth(number):
    return round(number * 10) / 10

def dot_product(arr, res, x):
    result = sum(a*b for a, b in zip(arr, res))
    return round_to_tenth(result) == x

def solve(n, arr, res, x, d=0):
    global count
    if d == n:
        if dot_product(arr, res, x):
            print(' '.join(map(str, res)))
            count += 1
    else:
        for i in [x * 0.25 for x in range(1, 41)]:
            res[d] = i
            solve(n, arr, res, x, d+1)

def main():
    n = int(input())
    if n >= 10:
        return
    arr = [float(input())/100 for _ in range(n)]
    res = [0.0]*n
    x = float(input())
    solve(n, arr, res, x)
    print(count)

if __name__ == "__main__":
    main()