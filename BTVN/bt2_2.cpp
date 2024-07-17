#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct Graph
{
    vector<string> v;
    map<string, set<string>> adj_list;
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph G;
    int tmp;
    string a, b;
    while(true)
    {
        cin >> tmp;
        if(tmp==1)
        {
            cin >> a;
            if(!G.v.empty())
            {
                vector<string>::iterator find_a = find(G.v.begin(), G.v.end(), a);
                if(find_a != G.v.end())
                {
                    cout << "DUP\n";
                    continue;
                }
                find_a = G.v.end();
            }
            G.v.push_back(a);
            G.adj_list[a];
            cout << "ADD\n";
        }
        else if(tmp==2)
        {
            cin >> a >> b;
            vector<string>::iterator find_a = find(G.v.begin(), G.v.end(), a);
            bool flag = false;
            if(find_a == G.v.end())
            {    
                G.v.push_back(a);
                G.adj_list[a];
                flag = true;
            }
            vector<string>::iterator find_b = find(G.v.begin(), G.v.end(), b);
            if(find_b == G.v.end())
            {
                G.v.push_back(b);
                G.adj_list[b];
                flag = true;
            }
            if(flag) 
            {
                G.adj_list[a].insert(b);
                cout << "ADD2\n";
                continue;
            }

            if(find_a != G.v.end() && find_b != G.v.end())
            {
                set<string>::iterator find_edge = G.adj_list[a].find(b);
                // auto find_edge = G.adj_list[a].find(b);
                if(find_edge != G.adj_list[a].end())
                    cout << "DUP2\n";
                else 
                {
                    G.adj_list[a].insert(b);
                    cout << "ADD3\n";
                }
            }
            find_a = G.v.end();
            find_b = G.v.end();
        }
        else if(tmp==3)
        {
            cin >> a >> b;     
            vector<string>::iterator find_a = find(G.v.begin(), G.v.end(), a);
            vector<string>::iterator find_b = find(G.v.begin(), G.v.end(), b);
            if(find_a == G.v.end() || find_b == G.v.end())
                cout << "FALSE\n";
            else
            {
                set<string>::iterator find_adj = G.adj_list[a].find(b);
                if(find_adj == G.adj_list[a].end())
                    cout << "FALSE\n";
                else
                    cout << "TRUE\n";
            }
            find_a = G.v.end();
            find_b = G.v.end();
        }
        else if(tmp==4)
        {
            cin >> a;
            vector<string>::iterator find_a = find(G.v.begin(), G.v.end(), a);
            if(find_a == G.v.end())
                cout << "0\n";
            else
                cout << G.adj_list[a].size() << "\n";
            find_a = G.v.end();
        }
        else 
            break;
    }
    return 0;
}