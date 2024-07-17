
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
class Graph {
private:
    std::vector<string> names;
    std::map<string, set<string>>G;
public:
    void inputGraph(int e){
        for (int i=0;i<e;i++){
            string a,b;
            std::cin>>a>>b;
            G[b];
            G[a].insert(b);
        }
    }
     void myProcess(int n) {
        for (int i = 0; i < n; i++) {
            int choice;
            std::cin >> choice;
            switch (choice) {
                case 1: {
                    std::string u, v;
                    std::cin >> u >> v;
                    set<string> s=G[u];
                    if (s.find(v) != s.end()){
                        std::cout << "TRUE" << std::endl;
                    } else {
                        std::cout << "FALSE" << std::endl;
                    }
                    break;
                }
                case 2: {
                    std::string u;
                    std::cin >> u;
                    int length=G[u].size();
                    cout<<length;
                    std::cout<<endl;
                    break;
                }
            }
        }
    }
};
int main()
{
    Graph G;
    int e, n; cin >> e >> n;
    G.inputGraph(e);
    G.myProcess(n);
    return 0;
}
