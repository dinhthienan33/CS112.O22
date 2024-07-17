#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5+5;
const int LOG = 20;
class Graph {
public:
    vector<int> g[MAXN];
    int up[MAXN][LOG];
    int tin[MAXN], tout[MAXN];
    int depth[MAXN];
    int timer;

    Graph() : timer(0) {}

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < LOG; i++)
            up[v][i] = up[up[v][i-1]][i-1];
        for (int to : g[v]) {
            if (to != p) {
                depth[to] = depth[v] + 1;
                dfs(to, v);
            }
        }
        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = LOG - 1; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    if(q==0){
        cout<<-1;
        return 0;
    }

    Graph graph;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph.g[a].push_back(b);
        graph.g[b].push_back(a);
    }
    graph.dfs(0, 0);
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        cout << graph.dist(a, b) << "\n";
    }
    return 0;
}