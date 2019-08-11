/*
https://szkopul.edu.pl/problemset/problem/_cVmDXXn2TjF0dF1rW6eazA0/site/?key=statement
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct fenwick {
    int n;
    vector<int> tree;
    fenwick(int n) : n(n) {
        tree.assign(n+1, 0);
    }
    void update(int p, int v) {
        while (p <= n) {
            tree[p] += v;
            p += p & -p;
        }
    }
    int sum(int p) {
        int res = 0;
        while (p >= 1) {
            res += tree[p];
            p -= p & -p;
        }
        return res;
    }
};

const ll mod = 1e9 + 7;

inline ll g(int n) {
    return (n+1) / 2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> p(n+1);
    vector<ll> f(n+1);
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        f[i] = (g(i)*(i-1) + f[i-1]*i) % mod;
    }
    fenwick tree(n);
    ll ans = 0;
    int min_so_far = n+1;
    for (int i = n; i >= 1; --i) {
        if (p[i] < min_so_far) {
            min_so_far = p[i];
        } else {
            ans += (ll)tree.sum(p[i]-1) * (g(n-i+1) + f[n-i]);
            ans %= mod;
        }
        tree.update(p[i], 1);
    }
    cout << ans << endl;
}
