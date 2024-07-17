from itertools import permutations
from datetime import datetime
def nam_nhuan(year):
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    if year % 4 == 0:
        return True
    return False

def hople(year, month, day):
    if year == 0:
        return False
    if month < 1 or month > 12:
        return False
    if day < 1 or day > 31:
        return False
    if month in [4, 6, 9, 11] and day > 30:
        return False
    if month == 2:
        if nam_nhuan(year) and day > 29:
            return False
        elif not nam_nhuan(year) and day > 28:
            return False
        elif(year>0 and year%3328==0 and month==2 and day==30):
            return True
    return True
def permute(data, i, length,listed): 
    if i==length: 
        listed.append(''.join(data))
    else: 
        for j in range(i,length): 
            data[i], data[j] = data[j], data[i] 
            permute(data, i+1, length,listed) 
            data[i], data[j] = data[j], data[i]
def main():
    date = input().split()
    dates=[]
    n=len(date)
    listed=[]
    permute(date,0,n,listed)
    for p in listed:
        year = int(''.join(p[:4]))
        month = int(''.join(p[4:6]))
        day = int(''.join(p[6:]))
        if hople(year, month, day):
            dates.append(datetime(year, month, day))
    dates = sorted(list(dates))
    print(len(dates))
    for date in dates:
        print(date.strftime("%Y %m %d"))
    print()
if __name__ == "__main__":
    main()