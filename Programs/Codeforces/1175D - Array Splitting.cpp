#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> suff(n);
    suff[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i) {
        suff[i] = suff[i+1] + a[i];
    }

    // minimize sum[1...n] + sum[r[1]+1...n] + sum[r[2]+2...n] + ... + sum[r[k-1]...n]
    // sum[1...n] is forced
    // for others, sort all suffix sums and take biggest

    ll ans = suff[0];

    suff.erase(suff.begin());
    sort(suff.begin(), suff.end());

    for (int i = suff.size()-1, j = 0; j < k-1; --i, ++j) {
        ans += suff[i];
    }

    cout << ans << '\n';

}
