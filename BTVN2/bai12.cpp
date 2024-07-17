#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
bool done=false;
void printBoard(vector<vector<int>> &board,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if(board[j][i]==1)
                cout << "X";
            else
                cout << ".";
        cout << "\n";
    }
}
void Try(int k, int n, vector<vector<int>> &board)
{
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < k; j++)
            if (board[i][j] == 1)
                check = false;
        for(int d=-min(i, k); d<min(n-i, n-k); d++)
			if(board[i+d][k+d]==1)
				check = false;

		for(int d=-min(n-1-i, k); d<=min(i, n-1-k); d++)
			if(board[i-d][k+d]==1)
				check = false;
        if (!check)
            continue;
        board[i][k] = 1;
        if (k == n - 1)
        {
            printBoard(board,n);
            done=true;
        }
        else
            Try(k + 1, n, board);
        if(done){
            break;
        }
        board[i][k] = 0;
    }
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    Try(0, n, board);
}
int main()
{
    solve();
    return 0;
}