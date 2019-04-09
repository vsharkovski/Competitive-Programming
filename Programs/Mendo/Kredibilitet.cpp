#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



// exes[y] has all x such that (x, y) exists, sorted in decreasing order
// used[y] means we have used that many x's in exes[y]

const int maxy = 10;

int n, f;
vector<int> exes[maxy+1];

map<vector<int>, int> dp;
vector<int> used;
int y_remaining;

int recurse(int done) {
    if (done == n) return 0;
    int& ans = dp[used];
    if (ans != 0) return ans;
    int x_max = 0;
    for (int y = 1; y <= maxy; ++y) {
        if (used[y] < exes[y].size()) {
            int x = exes[y][used[y]];
            if (x > x_max) {
                x_max = x;
                int opt = x * y_remaining;
                ++used[y];
                y_remaining -= y;
                opt += recurse(done+1);
                ans = max(ans, opt);
                y_remaining += y;
                --used[y];
            }
        }
    }
    if (done == n/2) ans += f * y_remaining;
    return ans;
}

void Main() {
    cin >> n >> f;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        exes[y].push_back(x);
    }
    y_remaining = 0;
    for (int y = 1; y <= maxy; ++y) {
        sort(exes[y].rbegin(), exes[y].rend());
        y_remaining += y * exes[y].size();
    }
    used.assign(maxy+1, 0);
    int ans = recurse(0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
