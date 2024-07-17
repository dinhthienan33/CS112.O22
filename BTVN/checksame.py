import difflib

def diff_files(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()

    diff = difflib.ndiff(lines1, lines2)

    for line in diff:
        if line.startswith('- ') or line.startswith('+ '):
            print(line)

# Call the function with the names of the files to compare
diff_files('file519.txt', 'file514.txt')