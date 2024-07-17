#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& arr,vector<int>& tem,vector<bool>& used,int n,int d=0){
    if(d==n){
        for (int i : tem) {
            cout << i << ' ';
        }
        cout << endl;
    }
    else{
        for (int i=0;i<n;i++){
            if(used[i]==false){
                used[i]=true;
                tem[d]=arr[i];
                solve(arr,tem,used,n,d+1);
                used[i]=false;
            }
        }
    }
    
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    vector<int> tem(n);
    vector<bool> used(n,false);
    solve(arr,tem,used,n);
}