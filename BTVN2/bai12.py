
def check(board, row, col,n):
	for i in range(col):
		if board[row][i] == 1:
			return False
	for i, j in zip(range(row, -1, -1),
					range(col, -1, -1)):
		if board[i][j] == 1:
			return False
	for i, j in zip(range(row, n, 1),
					range(col, -1, -1)):
		if board[i][j] == 1:
			return False

	return True
def backtrack(board, col,n):
	if col >= n:
		return True
	for i in range(n):
		if check(board, i, col,n):
			board[i][col] = 1
			if backtrack(board, col + 1,n) == True:
				return True
			board[i][col] = 0
	return False
def in_ket_qua(board,n):
	for i in range(n):
		for j in range(n):
			if board[i][j] == 1:
				print("X",end="")
			else:
				print(".",end="")
		print()
def main():
	n=int(input())
	board=[[0 for _ in range(n)] for _ in range(n)]
	if backtrack(board, 0,n):
		in_ket_qua(board,n)
if __name__ == '__main__':
	main()

