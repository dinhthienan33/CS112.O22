
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
class Graph {
private:
    std::vector<string> names;
    std::map<string, map<string,int>>G;
public:
    void inputGraph(int e){
        for (int i=0;i<e;i++){
            string a,b;
            int x;
            std::cin>>a>>b>>x;
            G[b];
            G[a].insert(b);
        }
    }
    bool isCycle( vector<string> x){
        set<string>s= G[x[0]];
        int i=1;
        int count=0;
        while(1){
            if(s.find(x[i])!=s.end()){
                count++;
                s=G[x[i]];
            }
            if(count==x.size())
                break;
            i++;
    }
        }
};
int main()
{
    Graph G;
    int e, n; cin >> e >> n;
    G.inputGraph(e);
    while(n--){
        vector<string> v;
        for 
        if(G.isCycle())
    }
    
    return 0;
}
