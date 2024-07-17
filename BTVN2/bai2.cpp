#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define INF INT_MAX

void printPath(vector<string> path) {
    for (auto v : path)
        cout << v << " ";
    cout<<path[0];
    cout << endl;
}
void TSP(map<string, map<string, int>> matrix, string s) {
    string start = s;
    int n = matrix.size();
    vector<string> path;
    map<string, bool> visited;

    for (auto node : matrix) {
        visited[node.first] = false;
    }

    int weight = 0;

    path.push_back(start);
    visited[start] = true;

    for (int i = 0; i < n - 1; i++) {
        int min_edge = INF;
        string vertex;

        for (auto node : matrix) {
            if (!visited[node.first] && matrix[path[i]][node.first] < min_edge) {
                min_edge = matrix[path[i]][node.first];
                vertex = node.first;
            }
        }

        path.push_back(vertex);
        visited[vertex] = true;
        weight += min_edge;
    }
    printPath(path);
}

int main() {
    map<string, map<string, int>> walks;
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (n--) {
        string u, i;
        int x;
        cin >> u >> i >> x;
        walks[u][i] = x;
    }

    TSP(walks, s);

    return 0;
}