#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int max_pages(int n, int x, vector<int>& price, vector<int>& pages) {
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= price[i]; --j) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int& p : price) cin >> p;
    for (int& p : pages) cin >> p;
    cout << max_pages(n, x, price, pages) << endl;
    return 0;
}