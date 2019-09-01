#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxw = 200010;
const int maxn = 2010;

int n, R, C;

vector<pii> pos;
int dp[maxn];

int fact[maxw];
int invfact[maxw];

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = ((ll)res * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    return res;
}

int nCr(int a, int b) {
    int res = fact[a];
    res = ((ll)res * invfact[b]) % mod;
    res = ((ll)res * invfact[a-b]) % mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < maxw; ++i) {
        fact[i] = ((ll)fact[i-1] * i) % mod;
        invfact[i] = ((ll)invfact[i-1] * powmod(i, mod-2)) % mod;
    }
    cin >> R >> C >> n;
    bool hadsrc = false, hadend = false;
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        pos.emplace_back(r, c);
        if (r == 1 && c == 1) {
            hadsrc = true;
        }
        if (r == R && c == C) {
            hadend = true;
        }
    }
    if (!hadsrc) pos.emplace_back(1, 1);
    if (!hadend) pos.emplace_back(R, C);
    sort(pos.begin(), pos.end());
    n = pos.size();
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        int ri = pos[i].first, ci = pos[i].second;
        dp[i] = nCr(ri-1 + ci-1, ri-1);
        for (int j = 1; j < i; ++j) {
            int rj = pos[j].first, cj = pos[j].second;
            if (cj <= ci) {
                dp[i] -= ((ll)dp[j] * nCr(ri-rj + ci-cj, ri-rj)) % mod;
                if (dp[i] < 0) dp[i] += mod;
            }
        }
    }
    cout << dp[n-1] << endl;
}
