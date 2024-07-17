#include<iostream>
    #include<vector>
    #include<string>
    #include<set>
    #include<unordered_map>
    #include<algorithm>
    using namespace std;
    class Graph {
    private:
        vector<string> vertices;
        unordered_map<string, set<string>>G;
    public:
        Graph() {
            vertices.reserve(1000);
        }
        void inputVertex(){
            string a; cin>>a;
            if(find(vertices.begin(),vertices.end(),a) != vertices.end()){
                cout<<"DUP"<<endl;
            }
            else{
                cout<<"ADD"<<endl;
                vertices.push_back(a);
                G[a];return;
            }
    }    
        void inputEdge() {
            string a, b;
            cin >> a >> b;
            unordered_map<string, set<string>>::iterator find_a = G.find(a);
            int flag = 0;
            if(find_a == G.end())
            {    
                vertices.push_back(a);
                G[a];
                flag = 1;
            }
            unordered_map<string, set<string>>::iterator find_b = G.find(b);
            if(find_b == G.end())
            {
                vertices.push_back(b);
                G[b];
                flag = 1;
            }
            if(flag==1) 
            {
                G[a].insert(b);
                cout << "ADD2"<<endl;
                return;
            }

            if(find_a != G.end() && find_b != G.end())
            {
                set<string>::iterator find_edge = G[a].find(b);
                if(find_edge != G[a].end())
                    cout << "DUP2"<<endl;
                else 
                {
                    G[a].insert(b);
                    cout << "ADD3"<<endl;
                    return;
                }
            }
        }
        void checkNeighbor(){
            string u, v;
            cin >> u >> v;
            set<string> s=G[u];
            if (s.find(v) != s.end()){
                cout << "TRUE" << endl;
            } else {
                cout << "FALSE" << endl;
            }
        }
        void findNeighbor(){
            string u;
            cin >> u;
            int length=G[u].size();
            cout<<length<<endl;
            return;
        }

    };
    int main()
    {
        Graph G;
        int n;
        do{
        cin>>n;
        switch (n) {
            case 1:
                G.inputVertex();
                break;
            case 2:
                G.inputEdge();
                break;
            case 3:
                G.checkNeighbor();
                break;
            case 4:
                G.findNeighbor();
                break;
        }} while(n!=0);
        return 0;
    }