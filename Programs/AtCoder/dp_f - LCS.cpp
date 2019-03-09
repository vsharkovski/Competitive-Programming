#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;







void Main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    static int dp[3005][3005];
    static pair<int, int> previ[3005][3005];
    previ[0][0] = {-1, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                if (dp[i][j] + 1 > dp[i+1][j+1]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    previ[i+1][j+1] = {i, j};
                }
            }
            if (dp[i][j] > dp[i+1][j]) {
                dp[i+1][j] = dp[i][j];
                previ[i+1][j] = {i, j};
            }
            if (dp[i][j] > dp[i][j+1]) {
                dp[i][j+1] = dp[i][j];
                previ[i][j+1] = {i, j};
            }
        }
    }
    int bi = 0, bj = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[i][m] > dp[bi][bj]) {
            bi = i, bj = m;
        }
    }
    for (int j = 0; j <= m; ++j) {
        if (dp[n][j] > dp[bi][bj]) {
            bi = n, bj = j;
        }
    }
    string ans = "";
    while (bi != 0 || bj != 0) {
        auto previous = previ[bi][bj];
        if (previous.first == bi-1 && previous.second == bj-1) {
            ans += s[bi-1];
        }
        bi = previous.first, bj = previous.second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
