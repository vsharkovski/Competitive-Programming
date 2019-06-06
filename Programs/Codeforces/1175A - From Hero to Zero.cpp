#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        ll n, k;
        cin >> n >> k;

        ll ans = 0;

        while (n > 0) {
            if (n % k == 0) {
                ans += 1;
                n /= k;
            } else {
                ans += n % k;
                n -= n % k;
            }
        }

        cout << ans << '\n';

    }

}
