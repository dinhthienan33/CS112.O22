#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> segments(n);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>segments[i];
        sum+=segments[i];
    }
    vector<bool> dp(sum+1, false);

    dp[0] = true;
    int count=0;
    for (int i = 0; i < segments.size(); i++) {
        for (int j = sum; j >= segments[i]; j--) {
            dp[j] = dp[j] || dp[j - segments[i]];
        }
    }
    for(int i = 1; i <= sum; i++){
        if(dp[i]){
            count++;
        }
    }
    cout<<count<<endl;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }

    return 0;
}