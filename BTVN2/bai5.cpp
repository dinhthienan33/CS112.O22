#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int v, e, n;
    cin >> v >> e >> n;
    vector<string> vertices(v);
    for(int i = 0; i < v; i++)
        cin >> vertices[i];
    map<string, vector<string>> graph;
    for(int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        graph[u];
        graph[v];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> colors(v);
    for(int i = 0; i < v; i++)
        cin >> colors[i];
    map<string, int> color_map;
    set<int> used_colors;
    for(int i = 0; i < v; i++) {
        color_map[vertices[i]] = colors[i];
        if(colors[i] != -1)
            used_colors.insert(colors[i]);
    }
    vector<string> ques(n);
    for(int i = 0; i < n; i++)
        cin >> ques[i];
    for(auto & i : ques) {
        if(color_map[i] != -1) {
            bool flag = true;
            for(auto & j : graph[i]) {
                if(color_map[j] == color_map[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << "TRUE" << endl;
                continue;
            }
        }
        for(auto & color : used_colors) {
            bool flag = true;
            for(auto & j : graph[i]) {
                if(color_map[j] == color) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                color_map[i] = color;
                cout << color << endl;
                break;
            }
        }
    }
    cout<<graph.size() << endl;
    return 0;
}