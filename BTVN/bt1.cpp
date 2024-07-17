
#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    map<int, list<int>> adjList;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(matrix[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    for(auto i : adjList)
    {
        cout << i.first+1 << "->";
        for(auto j : i.second)
        {
            cout << j+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}