#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxm = 1010;

int m;
bool okay[11];
bool dp[maxm][11][11];
vector<int> seq;

bool dfs(int i, int d, int p) {
    if (dp[i][d][p]) {
        return false;
    }
    dp[i][d][p] = true;
    if (i == m) {
        return true;
    }
    for (int c = d+1; c <= 10; ++c) {
        if (okay[c] && c != p && dfs(i+1, c-d, c)) {
            seq.push_back(c);
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();

    for (int i = 1; i <= 10; ++i) {
        char ch;
        cin >> ch;
        okay[i] = (ch-'0');
    }
    cin >> m;

    memset(dp, false, sizeof(dp));

    if (dfs(0, 0, 0)) {
        cout << "YES\n";
        for (int i = m-1; i >= 0; --i) {
            cout << seq[i] << ' ';
        }
    } else {
        cout << "NO\n";
    }
}

