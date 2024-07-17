def backtrack(start, string, result):
    if start > len(string):
        return
    for end in range(start+1, len(string)+1):
        result.append(string[start:end])
        backtrack(end, string, result)

def print_substrings(string):
    result = []
    backtrack(0, string, result)
    for substring in result:
        print(substring)

# Example usage
string = "hello"
print_substrings(string)