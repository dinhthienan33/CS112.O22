    #include<iostream>
    #include<vector>
    #include<string>
    #include<algorithm>

    using namespace std;

    struct Project {
        int start, end, credit;
    };
    bool compare(Project s1, Project s2) {
        return (s1.end < s2.end);
    }
    int binarySearch(const vector<Project> &P, int n) {
        int l = 1, r = n - 1;
        while (l <= r) {
            int mid =(l+r)/2;
            if (P[mid].end < P[n].start) {
                if (P[mid + 1].end < P[n].start) 
                    l = mid + 1;
                else
                    return mid;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

    void solve() {
        int n; 
        cin >> n;
        vector<Project> P(n+1);
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));

        for(int i = 0; i <n; i++) 
            cin >> P[i].start >> P[i].end >> P[i].credit;
        sort(P.begin(), P.end(), compare);
        dp[1][1] = P[1].credit;
        for(int i = 2;i <= n; i++) {
            int mid = binarySearch(P, i);
            if(mid != -1)
                dp[i][1] = max(dp[mid][0], dp[mid][1]) + P[i].credit;
            dp[i][0] = max({dp[i-1][0], dp[i-1][1],(long long)P[i].credit});
        }

        cout << max(dp[n][0], dp[n][1]) << endl;
    }

    int main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        solve();
        return 0;
    }