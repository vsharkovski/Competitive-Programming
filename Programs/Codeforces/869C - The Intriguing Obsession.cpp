#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const ll mod = 998244353;
const int maxn = 5005;

ll CHS[maxn][maxn];
ll Fact[maxn];

ll solve(int a, int b) {
    ll ans = 0;
    for (int e = 0; e <= min(a, b); ++e) {
        // a red nodes, b blue nodes, factorial ways to shuffle edges
        ll res = 1;
        res = (res * CHS[a][e]) % mod;
        res = (res * CHS[b][e]) % mod;
        res = (res * Fact[e]) % mod;
        ans = (ans + res) % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    Fact[0] = 1;
    for (ll x = 1; x < maxn; ++x) {
        Fact[x] = (Fact[x-1] * x) % mod;
    }

    for (int i = 0; i < maxn; ++i) {
        CHS[i][0] = CHS[i][i] = 1;
        for (int j = i+1; j < maxn; ++j) {
            CHS[i][j] = 0;
        }
        if (i > 0) {
            for (int j = 1; j < i; ++j) {
                CHS[i][j] = (CHS[i-1][j-1] + CHS[i-1][j]) % mod;
            }
        }
    }

    int a[3] = {};
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }

    ll ans = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = i+1; j < 3; ++j) {
            ans = (ans * solve(a[i], a[j])) % mod;
        }
    }

    cout << ans << '\n';

}
