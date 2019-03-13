#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int N, C;
    cin >> N >> C;
    vector<pi> cities;
    for (int i = 0; i < C; ++i) {
        int r, p;
        cin >> r >> p;
        cities.emplace_back(r, p);
    }
    sort(cities.begin(), cities.end(), [&] (pi& x, pi & y) {
        return x.second > y.second;
    });
    vector<vector<int>> dp(C+1, vector<int>(N+1, 0));
    int ans = 0;
    for (int i = 0; i < C; ++i) {
        for (int j = N; j >= 0; --j) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j >= cities[i].first) {
                int j1 = j - cities[i].first + cities[i].second;
                dp[i+1][j1] = max(dp[i+1][j1], dp[i][j] + 1);
                ans = max(ans, dp[i+1][j1]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
