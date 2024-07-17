def solve(num):
    def backtrack(index, path):
        if len(path) >= 3 and index == len(num):
            return True
        for i in range(index, len(num)):
            curr = num[index:i+1]
            if curr[0] == '0' and len(curr) != 1:
                continue
            if len(path) >= 2 and int(curr) > int(path[-1]) + int(path[-2]):
                break
            if len(path) < 2 or int(curr) == int(path[-1]) + int(path[-2]):
                if backtrack(i+1, path + [curr]):
                    return True
        return False
    return "true" if backtrack(0, []) else "false"

num = input().strip()
print(solve(num))