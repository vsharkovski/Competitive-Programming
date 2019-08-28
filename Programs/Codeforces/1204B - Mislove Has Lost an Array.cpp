#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    ll minsum = 0, maxsum = 0;
    minsum += n - (l-1);
    for (ll i = 0, j = 2; i < l-1; ++i, j *= 2) {
        minsum += j;
    }
    for (ll i = 0, j = 1; i < r-1; ++i, j *= 2) {
        maxsum += j;
    }
    maxsum += (n-(r-1)) * (1LL << (r-1));
    cout << minsum << ' ' << maxsum << endl;
}
