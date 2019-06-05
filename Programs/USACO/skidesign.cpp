#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: skidesign
*/


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    #endif // _DEBUG

    int n;
    int cnt[101] = {};

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        ++cnt[h];
    }

    int ans = 1e9;

    for (int x = 0; x + 17 <= 100; ++x) {
        int res = 0;
        for (int y = 0; y < x; ++y) {
            res += cnt[y] * (x-y) * (x-y);
        }
        for (int y = x+18; y <= 100; ++y) {
            res += cnt[y] * (y-(x+17)) * (y-(x+17));
        }
//        cout << "[x, x+17] = [" << x << ", " << x+17 << "] res=" << res << "\n";
        ans = min(ans, res);
    }
    cout << ans << '\n';

}
