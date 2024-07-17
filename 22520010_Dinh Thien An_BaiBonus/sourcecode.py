import sys
#Hàm nhập dữ liệu 
def input_graph(Grid, n, m):
    for i in range(m):
        line = list(map(float, sys.stdin.readline().split()))
        for j in range(n):
            if(j<len(line)):
                Grid[i][j] = line[j]
        Grid[i][n+1] = line[-1]
    line = list(map(float, sys.stdin.readline().split()))
    for j in range(n):
        Grid[m][j] =-line[j]
    Grid[m][n] = 1

def FourierMotzkin(Grid, n):
    history = [] #Lưu lại các ma trận đã giải để tìm các ẩn
    result = []
    for _ in range(n): # Đối với mỗi ẩn
        history.append(Grid)
        pos = [] # Lưu hệ số dương
        neg = [] # Lưu hệ số âm
        temp = []
        for j in range(len(Grid)):
            if Grid[j][0] > 0:
                pos.append(j)
            elif Grid[j][0] < 0:
                neg.append(j)
            else:
                row = Grid[j][1:]
                temp.append(row)

        for ps in pos:
            for ng in neg:
                row = [Grid[ng][k]*Grid[ps][0] - Grid[ps][k]*Grid[ng][0] for k in range(1, len(Grid[0]))] #Tìm các cặp bất phương trình để ghép lại
                temp.append(row)
        Grid = temp

    z = float("inf")
    for i in range(len(Grid)):
        if Grid[i][0] > 0 and z > Grid[i][1] / Grid[i][0]: #Tìm đáp án lớn nhất
            z = Grid[i][1] / Grid[i][0]
    result.append(z)
    while history: #Thế z vào để tìm các ẩn
        Grid = history.pop()
        l = len(Grid[0]) - 1

        for i in range(len(Grid)):
            for j in range(1, l):
                Grid[i][l] -= result[j-1]*Grid[i][j]

        end = False
        epsilon = 1e-6
        for i in range(len(Grid) - 1):
            for j in range(i+1, len(Grid)):
                if Grid[i][0]*Grid[j][0] <-epsilon and abs(Grid[i][0]*Grid[j][l] - Grid[i][l]*Grid[j][0]) < epsilon:
                    result.insert(0, Grid[i][l] / Grid[i][0])
                    end = True
                    break
            if end:
                break

    return result

def main():
    n, m = map(int, sys.stdin.readline().split())
    Grid = [[0]*(n+2) for _ in range(m+1)]
    input_graph(Grid, n, m)
    res = FourierMotzkin(Grid, n)
    for i in res:
        print(i, end=" ")
if __name__ == "__main__":
    main()