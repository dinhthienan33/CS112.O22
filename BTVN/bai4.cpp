#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(string& a,string& temp,vector<bool>& used,int n,int d=0){
    if(d==n){
        for (auto i:temp) {
            cout << i;
        }
        cout << endl;
    }
    else{
        for (int i=0;i<n;i++){
            if(used[i]==false){
                used[i]=true;
                temp[d]=a[i];
                solve(a,temp,used,n,d+1);
                used[i]=false;
            }
        }
    }
}
int main(){
    string a;
    cin>>a;
    reverse(a.begin(),a.end());
    int n=a.size();
    string temp(n, 'a');
    vector<bool> used(n,false);
    solve(a,temp,used,n);

}