#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct Graph {
    vector<string> vertices;
    unordered_map<string, set<string>> G;
    void addVertex(const string& a) {
        if(!vertices.empty()) {
            auto find_a = G.find(a);
            if(find_a != G.end()) {
                cout << "DUP\n";
                return;
            }
        }
        vertices.push_back(a);
        G[a];
        cout << "ADD"<<endl;
    }
    void addEdge(const string& a, const string& b) {
        auto find_a = G.find(a);
        int flag = 0;
        if(find_a == G.end()) {    
            vertices.push_back(a);
            G[a];
            flag = 1;
        }
        auto find_b = G.find(b);
        if(find_b == G.end()) {
            vertices.push_back(b);
            G[b];
            flag = 1;
        }
        if(flag) {
            G[a].insert(b);
            cout << "ADD2"<<endl;
            return;
        }

        if(find_a != G.end() && find_b != G.end()) {
            auto find_edge = G[a].find(b);
            if(find_edge != G[a].end())
                cout << "DUP2"<<endl;
            else {
                G[a].insert(b);
                cout << "ADD3"<<endl;
            }
        }
    }

    void checkEdge(const string& a, const string& b) {
        auto find_a = G.find(a);
        auto find_b = G.find(b);
        if(find_a == G.end() || find_b == G.end())
            cout << "FALSE"<< endl;
        else {
            auto find_edge = G[a].find(b);
            if(find_edge == G[a].end())
                cout << "FALSE"<<endl;
            else
                cout << "TRUE"<<endl;
        }
    }

    void countEdges(const string& a) {
        auto find_a = G.find(a);
        if(find_a == G.end())
            cout << "0"<<endl;
        else
            cout << G[a].size() <<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Graph G;
    G.vertices.reserve(1000);
    int n;
    string a, b;
     while(true) {
        cin >> n;
        if(n==1) {
            cin >> a;
            G.addVertex(a);
        }
        else if(n==2) {
            cin >> a >> b;
            G.addEdge(a, b);
        }
        else if(n==3) {
            cin >> a >> b;
            G.checkEdge(a, b);
        }
        else if(n==4) {
            cin >> a;
            G.countEdges(a);
        }
        else 
            break;
    }
    return 0;
}