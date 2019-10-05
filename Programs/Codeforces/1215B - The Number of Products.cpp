#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll ans[2] = {};
    ll cnt[2] = {}, p = 0;
    ++cnt[0];
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 0) ++p;
        if (p == 2) p = 0;
        ans[1] += cnt[p];
        ans[0] += cnt[1-p];
        cnt[p] += 1;
    }
    cout << ans[0] << ' ' << ans[1] << endl;
}
