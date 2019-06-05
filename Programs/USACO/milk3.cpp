#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: milk3
*/

int A, B, C;
bool dp[21][21][21];

void dfs(int a, int b, int c) {
    if (dp[a][b][c]) {
        return;
    }
    dp[a][b][c] = true;
    int e;
    e = min(a, B - b);
    dfs(a - e, b + e, c);
    e = min(a, C - c);
    dfs(a - e, b, c + e);
    e = min(b, A - a);
    dfs(a + e, b - e, c);
    e = min(b, C - c);
    dfs(a, b - e, c + e);
    e = min(c, A - a);
    dfs(a + e, b, c - e);
    e = min(c, B - b);
    dfs(a, b + e, c - e);
}

int main() {
    #ifndef _DEBUG
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> A >> B >> C;

    for (int a = 0; a <= A; ++a) {
        for (int b = 0; b <= B; ++b) {
            for (int c = 0; c <= C; ++c) {
                dp[a][b][c] = false;
            }
        }
    }

    dfs(0, 0, C);

    vector<int> ans;

    for (int b = 0; b <= B; ++b) {
        for (int c = 0; c <= C; ++c) {
            if (dp[0][b][c]) {
                ans.push_back(c);
            }
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

}
