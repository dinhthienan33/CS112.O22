#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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
    int h = jobs.size();
    int k = jobs[0].size();

// Create a 2D vector with dimensions m x n
std::vector<std::vector<int>> transposed(k, std::vector<int>(h));

// Transpose the jobs matrix
for (int i = 0; i < h; ++i) {
    for (int j = 0; j < k; ++j) {
        transposed[j][i] = jobs[i][j];
    }
}
    //std::vector<std::vector<int>> checked(n, std::vector<int>(m));
    int count=0;
    int check=1000000;
    int res=0;
    vector<int> last(n,0);
    while(count!=10000) {
        vector<int> result(n,0);
        vector<int>temp(m,0);
            for(int j=0;j<n;j++){
                int randomIndex = rand() % m; // Generate a random index
                temp[randomIndex]+=transposed[j][randomIndex];
                result[j]=randomIndex;
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
        //std::cout<<res;
    return 0;
}