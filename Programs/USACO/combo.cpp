#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: combo
LANG: C++
*/

bool okay(int n, vector<int>& a, vector<int>& b) {
    for (int i = 0; i < 3; ++i) {
        int x = a[i], y = b[i];
        bool good = false;
        for (int j = 0; j < 2; ++j) {
            if (x == n-1 && (y == n || y == 1)) {
                good = true;
                break;
            }
            if (x == n && (y == 1 || y == 2)) {
                good = true;
                break;
            }
            if (y-2 <= x && x <= y+2) {
                good = true;
                break;
            }
            swap(x, y);
        }
        if (good == false) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<vector<int>> valid;
    for (int i = 0; i < 2; ++i) {
        valid.push_back(vector<int>());
        for (int j = 0; j < 3; ++j) {
            int x;
            cin >> x;
            valid.back().push_back(x);
        }
    }

    int ans = 0;

    vector<int> curr(3);
    for (curr[0] = 1; curr[0] <= n; ++curr[0]) {
        for (curr[1] = 1; curr[1] <= n; ++curr[1]) {
            for (curr[2] = 1; curr[2] <= n; ++curr[2]) {
                for (vector<int>& v : valid) {
                    if (okay(n, curr, v)) {
                        ++ans;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << '\n';

}
