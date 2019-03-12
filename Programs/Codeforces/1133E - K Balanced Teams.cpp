#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> optimal(n);
    for (int i = 0; i < n; ++i ){
        int nxt = i;
        while (nxt < n && a[i] + 5 >= a[nxt]) {
            ++nxt;
        }
        optimal[i] = nxt - i;
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j < k) {
                dp[i+optimal[i]][j+1] = max(dp[i+optimal[i]][j+1], dp[i][j] + optimal[i]);
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= k; ++j) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
