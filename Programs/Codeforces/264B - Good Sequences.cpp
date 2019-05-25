#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




const int maxval = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie();

    bitset<maxval> composite;
    vector<int> primes;
    for (ll p = 2; p < maxval; ++p) {
        if (composite[p]) continue;
        primes.push_back(p);
        for (ll q = p*p; q < maxval; q += p) {
            composite[q] = 1;
        }
    }

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 1;
    vector<int> dp(maxval, 0);

    for (int i = 0; i < n; ++i) {
        vector<int> prime_divs;
        int x = a[i];
        int res = 1;
        for (int p : primes) {
            if (p*p > x) {
                break;
            }
            if (x % p == 0) {
                prime_divs.push_back(p);
                res = max(res, 1 + dp[p]);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) {
            prime_divs.push_back(x);
            res = max(res, dp[x] + 1);
        }
        ans = max(ans, res);
        for (int p : prime_divs) {
            dp[p] = res;
        }
    }

    cout << ans << '\n';

}

