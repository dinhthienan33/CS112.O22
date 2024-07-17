#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
vector<pair<int, int>> sortAndKeepIndex(vector<int> vec) {
    vector<pair<int, int>> vecWithIndex;
    for (int i = 0; i < vec.size(); ++i) {
        vecWithIndex.push_back({vec[i], i});
    }

    sort(vecWithIndex.begin(), vecWithIndex.end(), greater<pair<int, int>>());

    return vecWithIndex;
}

void solve(vector<int> &jobs,int n,int m) {
    
    vector<pair<int, int>> sorted_vec=sortAndKeepIndex(jobs);
     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> machines;
    for (int i = 0; i < m; ++i) {
        machines.push({0, i});
    }
    vector<int> assignment(n,0);
    for (auto &i : sorted_vec){
        pair<long long, int> machine = machines.top();
        machines.pop();
        assignment[i.second] = machine.second;
        machine.first +=i.first;
        machines.push(machine);
    }

    for (int i = 0; i < n; ++i) {
        cout << assignment[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i];
    }
    solve(jobs,n,m);
    return 0;
}