#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <queue>
using namespace std;

#define INF 1e9

int n;
map<string, int> cityIndex;
vector<string> indexCity;
vector<vector<int>> graph;
vector<bool> visited;
int best_path = INF;
vector<int> best_route, route;

void tsp(int v, int cost, int count) {
    if (count == n && graph[v][cityIndex["s"]]) {
        if (cost + graph[v][cityIndex["s"]] < best_path) {
            best_path = cost + graph[v][cityIndex["s"]];
            best_route = route;
        }
        return;
    }

    for (int u = 0; u < n; u++) {
        if (!visited[u] && graph[v][u]) {
            visited[u] = true;
            route.push_back(u);
            tsp(u, cost + graph[v][u], count + 1);
            visited[u] = false;
            route.pop_back();
        }
    }
}

int main() {
    int e;
    string s, u, i;
    int x;
    cin >> e >> s;
    while (e--) {
        cin >> u >> i >> x;
        if (!cityIndex.count(u)) {
            cityIndex[u] = n;
            indexCity.push_back(u);
            n++;
        }
        if (!cityIndex.count(i)) {
            cityIndex[i] = n;
            indexCity.push_back(i);
            n++;
        }
        if (graph.size() < n) graph.resize(n, vector<int>(n));
        graph[cityIndex[u]][cityIndex[i]] = x;
    }

    visited.resize(n);
    visited[cityIndex[s]] = true;
    route.push_back(cityIndex[s]);
    tsp(cityIndex[s], 0, 1);

    for (int i : best_route) {
        cout << indexCity[i] << " ";
    }
    cout << s << endl;
    cout << "Best path length: " << best_path << endl;
    return 0;
}