#include <iostream>
#include <vector>
#include <string>

void solve(std::string ip, std::string ans, int count, int pos) {
    int n = ip.size();
    if(count != 4 or pos != n){
        for (int i = 1; i <= 3; i++) {
            if (pos + i <= n) {
                std::string segment = ip.substr(pos, i);
                int val = std::stoi(segment);
                if (val <= 255) {
                    solve(ip, ans + segment + ".", count + 1, pos + i);
                }
            }
        }
    }
    else{
        ans.pop_back();
        std::cout << ans << std::endl;
        return;
    }
}
int main() {
    std::string ip;
    std::cin>>ip;
    solve(ip, "", 0, 0);
    return 0;
}