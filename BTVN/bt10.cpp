#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include<list>
using namespace std;

int main(){
    srand(time(0));
    int n,m;
    cin >> n >> m;
    vector<vector<int> > jobs(m,vector<int>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin >> jobs[i][j];
        }
    }
std::vector<std::vector<int>> transposed(n, std::vector<int>(m));

for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
        transposed[j][i] = jobs[i][j];
    }
}
vector<list<int>>mang_dem(n,list<int>());
for (int i=0;i<n; ++i) {
    for(int j=0;j<m;j++) {
        if(transposed[i][j]!=-1){
           mang_dem[i].push_back(j);
        }
    }
}
    int count=0;
    int check=1000000;
    int res=0;
    vector<int> last(n,0);
    while(count!=10000) {
        vector<int> result(n,0);
        vector<int>temp(m,0);
            for(int j=0;j<n;j++){
                int randomIndex = rand() % mang_dem[j].size();
                auto list_iter = std::next(mang_dem[j].begin(), randomIndex);
                int ranIn = *list_iter;
                temp[ranIn]+=transposed[j][ranIn];
                result[j]=ranIn;
            }
        auto max_number=max_element(temp.begin(), temp.end());
        res=*max_number;
        if(res<check){
            check=res;
            last=result;
        } 
        count++;
   }
    for (auto i : last) {
        cout << i << ' ';
    }
    return 0;
}