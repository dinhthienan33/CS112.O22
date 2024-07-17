#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve(int mo, int dong, string str) {
    if (mo == 0 && dong == 0) { 
        cout << str << endl;
        return;
    }
    if (mo > 0) {  
        solve(mo - 1, dong, str + "(");
    }
    if (dong > mo) {
        solve(mo, dong - 1, str + ")");
    }
}

int main() {
    int n;
    cin >> n;
    solve(n, n, "");
    return 0;
}