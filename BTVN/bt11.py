from itertools import product
import cProfile
def solve(jobs, m, n):
    check = float('inf')
    result = None
    avg_load = sum(jobs) / m
    for schedule in product(range(m), repeat=n):
        loads = []
        for i in range(m):
            total = 0
            for j in range(n):
                if schedule[j] == i:
                    total += jobs[j]
                    if(total>check):
                        continue
            loads.append(total)
        max_load = max(loads)
        if max_load < check:
            check = max_load
            result = schedule
        if max_load == avg_load:
            break

    return result
n, m = map(int, input().split())
if(n<=0 or m>=50):
    exit
jobs = list(map(int, input().split()))
schedule = solve(jobs, m, n)
print(' '.join(map(str, schedule)))
cProfile.run('solve(jobs, m, n)')
