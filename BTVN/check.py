
def check_zero():
    zero = []
    with open('file519.txt', 'r') as file:
        content = file.readlines()
        for line in content:
            for number in line.split():
                if (number)=='0':
                    zero.append(number)
    file.close()
    print(' '.join(zero))
def check_duplicate():
    duplicate=[]
    duplicate_found = False
    with open('file519.txt', 'r') as file:
        content = file.readlines()
        for line in content:
            if line not in duplicate:
                duplicate.append(line)
            else:
                print('Duplicate found:', line)
                duplicate_found = True
    if duplicate_found==False:
        print('No duplicates found')
    file.close()
def main():
    check_zero()
    check_duplicate()
if __name__ == '__main__':
    main()