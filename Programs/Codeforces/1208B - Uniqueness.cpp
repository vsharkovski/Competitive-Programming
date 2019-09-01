#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int cnt1 = 0, nd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mp[a[i]] == 0) {
            ++nd;
            ++cnt1;
        }
        if (mp[a[i]] == 1) {
            --cnt1;
        }
        ++mp[a[i]];
    }
    if (cnt1 == nd) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (mp[a[j]] == 1) {
                --cnt1;
            } else if (mp[a[j]] == 2) {
                ++cnt1;
            }
            --mp[a[j]];
            if (cnt1 == n - (j-i+1)) {
                ans = min(ans, j-i+1);
            }
        }
        for (int j = i; j < n; ++j) {
            if (mp[a[j]] == 0) {
                ++cnt1;
            } else if (mp[a[j]] == 1) {
                --cnt1;
            }
            ++mp[a[j]];
        }
    }
    cout << ans << endl;
}
