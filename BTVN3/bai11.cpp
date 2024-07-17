#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item {
    int weight, value;
};
int main() {
    int n, x;
    cin >> n >> x;
    vector<Item> I(n+1);
    for(int i = 0; i < n; i++) {
        cin >> I[i].weight >> I[i].value;
    }
    vector<long long> dp(x + 1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = x; j >= 1; j--) {
            if(I[i].weight <= j)
                dp[j] = max(dp[j], dp[j-I[i].weight] + I[i].value);
            else continue;
        }
    }
    cout << dp[x];
    return 0;
}