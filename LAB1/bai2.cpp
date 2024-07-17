/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph {
private:
    int v;
    std::vector<std::vector<int>> grid;
    std::vector<std::string> names;
    std::map<std::string, int> mapping;

public:
    void nhap(int vertices, int edges) {
        v = vertices;
        grid = std::vector<std::vector<int>>(v, std::vector<int>(v, 0));
        names = std::vector<std::string>(v, "");
        std::string x;
        for (int i = 0; i < v; i++) {
            std::cin >> x;
            names[i] = x;
            mapping[x] = i;
        }
        std::string a, b;
        for (int i = 0; i < edges; i++) {
            std::cin >> a >> b;
            grid[mapping[a]][mapping[b]] = 1;
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
                    if (grid[mapping[u]][mapping[v]] == 1) {
                        std::cout << "TRUE" << std::endl;
                    } else {
                        std::cout << "FALSE" << std::endl;
                    }
                    break;
                }
                case 2: {
                    std::string u;
                    std::cin >> u;
                    bool flag = false;
                    for (int i = 0; i < v; i++) {
                        if (grid[mapping[u]][i] == 1) {
                            flag = true;
                            std::cout << names[i] << " ";
                        }
                    }
                    if (!flag) {
                        std::cout << "NONE";
                    }
                    std::cout << std::endl;
                    break;
                }
            }
        }
    }
};

int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

