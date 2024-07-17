with open('pupput.txt', 'r') as f:
    reader = f.readlines()

with open('output7.txt', 'r') as f:
    reader_1 = f.readlines()

for line1, line2 in zip(reader, reader_1):
    if line1 != line2:
        print(f"The files are different at line: {reader.index(line1) + 1}")
        break
else:
    print("The files are identical.")