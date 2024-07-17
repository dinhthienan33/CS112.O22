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
    vector<int> jobs(n);
    for (int i=0;i<n;i++){
        cin>>jobs[i];
    }
    int count=0;
    int check=1000000;
    int res=0;
    vector<int> last(n,0);
    while(count!=10000) {
        vector<int> result(n,0);
        vector<int>temp(m,0);
            for(int j=0;j<n;j++){
                int randomIndex = rand() % m;
                temp[randomIndex]+=jobs[j];
                result[j]=randomIndex;
                }
        auto max_number=max_element(temp.begin(), temp.end());
        res=*max_number;
        if(res<check){
            check=res;
            res=0;
            last=result;
        }
        count++;
   }
    for (auto i : last) {
        cout << i << ' ';
    }
    return 0;
}