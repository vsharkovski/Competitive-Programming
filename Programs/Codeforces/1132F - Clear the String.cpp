#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;






int n;
string s;

int dp[505][505];

int dfs(int i, int j) {
    int& res = dp[i][j];
    if (res == -1) {
        if (i > j) {
            res = 0;
        } else if (i == j) {
            res = 1;
        } else {
            res = 1 + dfs(i+1, j);
            res = min(res, dfs(i, j-1) + 1);
            for (int k = i; k <= j; ++k) {
                if (s[i] == s[k]) {
                    res = min(res, dfs(i+1, k-1) + dfs(k, j));
                }
            }
        }
    }
    return res;
}

void Main() {
    cin >> n >> s;
    string s1 = "";
    char previ = '1';
    for (int i = 0; i < n; ++i) {
        if (s[i] != previ && i > 0) {
            s1 += previ;
        }
        previ = s[i];
    }
    s1 += previ;
    s = s1;
    n = s.length();
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, n-1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
