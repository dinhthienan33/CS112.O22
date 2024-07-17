#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
#include <string>

using namespace std;

bool done = false;

void Try(int k, int n, vector<vector<char>> board){
	for(int i=0; i<n; i++){
		bool valid = true;
		for(int j=0; j<k; j++)
			if(board[i][j]=='X')
				valid = false;

		for(int d=-min(i, k); d<min(n-i, n-k); d++)
			if(board[i+d][k+d]=='X')
				valid = false;

		for(int d=-min(n-1-i, k); d<=min(i, n-1-k); d++)
			if(board[i-d][k+d]=='X')
				valid = false;

		if(!valid)
			continue;

		board[i][k] = 'X';
		if(k==n-1){
			for(int I=0; I<n; I++){
				for(int j=0; j<n; j++)
					cout<<board[j][I];
				cout<<endl;
			}
			done=true;
			//cout<<endl;
		}
		else
			Try(k+1, n, board);
		if(done)
			break;
		board[i][k] = '.';
	}
}

void solve(){
	int n; cin>>n;
	vector<vector<char>> board(n, vector<char>(n, '.'));
	Try(0, n, board);
}

int main(){
	solve();
}