#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const ll p = 101;
const ll pi = 940594066;

const int maxn = 1000010;

ll powp[maxn];
ll powpi[maxn];

int val[256];

void make_hash(string &s, vector<ll> &h) {
    h.resize(s.length());
    h[0] = val[s[0]];
    for (int i = 1; i < (int)s.length(); ++i) {
        h[i] = (h[i-1] + powp[i]*val[s[i]]) % mod;
    }
}

ll subhash(vector<ll> &h, int l, int r) {
    ll res = h[r];
    if (l) {
        res -= h[l-1];
        if (res < 0) res += mod;
    }
    res = (res * powpi[l]) % mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string mapz = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < (int)mapz.size(); ++i) {
        val[mapz[i]] = i+1;
    }
    powp[0] = 1;
    powpi[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        powp[i] = (powp[i-1]*p)%mod;
        powpi[i] = (powpi[i-1]*pi)%mod;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> hs;
    make_hash(s, hs);
    for (int w = 1; w < n; ++w) {
        string t;
        cin >> t;
        vector<ll> ht;
        make_hash(t, ht);
        int res = -1;
        for (int ti = t.length()-1, si = s.length()-t.length(); ti >= 0; --ti, ++si) {
            if (si < 0) continue;
            if (subhash(hs, si, s.length()-1) == subhash(ht, 0, ti)) {
                res = ti;
                break;
            }
        }
        for (int i = res+1; i < (int)t.length(); ++i) {
            s += t[i];
            hs.push_back((hs.back() + powp[s.length()-1]*val[t[i]]) % mod);
        }
    }
    cout << s << endl;
}
