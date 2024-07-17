#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        arr[i] += arr[i-1];
    }
    while(q--) {
        int first, last;
        cin >> first >> last;
        first--; last--;
        if(first > 0) {
            cout << arr[last] - arr[first-1] << endl;
        } else {
            cout << arr[last] << endl;
        }
    }
    return 0;
}