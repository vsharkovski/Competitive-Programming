#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxk = 100005;

ll n, k;
ll a[maxk];

int simulate(ll a0) {
    a[0] = a0;
    ll sumsofar = a0;
    for (ll i = 1; i < k; ++i) {
        ll lo = a[i-1]+1, hi = 2*a[i-1], mid, res = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            ll minsum = sumsofar + mid*(k-i) + (k-i-1)*(k-i)/2;
            if (minsum > n) {
                hi = mid-1;
            } else if (minsum == n) {
                res = mid;
                break;
            } else {
                // minsum < n
                if (k-i >= 30) { // maxsum > n, no need to calculate
                    res = mid;
                    hi = mid-1;
                } else {
                    ll maxsum = sumsofar + mid*((1LL<<(k-i)) - 1);
                    if (maxsum < n) {
                        lo = mid+1;
                    } else if (maxsum == n) {
                        res = mid;
                        break;
                    } else {
                        // maxsum > n
                        res = mid;
                        hi = mid-1;
                    }
                }
            }
        }
        if (res == -1) {
            ll minsum = sumsofar + mid*(k-i) + (k-i-1)*(k-i)/2;
            if (minsum > n) {
                return 1;
            } else {
                return -1;
            }
        } else {
            a[i] = res;
            sumsofar += res;
        }
    }
    return 0;
}

int main() {
    cin >> n >> k;
    if (k == 1) {
        cout << "YES\n" << n << "\n";
        return 0;
    }
    ll lo = 1, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        ll res = simulate(mid);
        if (res == -1) {
            lo = mid+1;
        } else if (res == 1) {
            hi = mid-1;
        } else { // res == 0
            cout << "YES\n";
            for (int i = 0; i < k; ++i) {
                cout << a[i] << ' ';
            }
            return 0;
        }
    }
    cout << "NO\n";
}
