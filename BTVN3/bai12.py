from typing import List

def solve(s: str, memo: dict = {}) -> List[int]:
    if s in memo:
        return memo[s]
    if '*' not in s and '+' not in s and '-' not in s:
        return [int(s)]
    res = []
    for i in range(len(s)):
        if s[i] in "+-*":
            res1 = solve(s[:i], memo)
            res2 = solve(s[i+1:], memo)
            for r1 in res1:
                for r2 in res2:
                    if s[i] == '+':
                        res.append(r1 + r2)
                    elif s[i] == '-':
                        res.append(r1 - r2)
                    else:
                        res.append(r1 * r2)
    memo[s] = res
    return res

s = input().strip()
res = solve(s)
res.sort()
for r in res:
    print(r)