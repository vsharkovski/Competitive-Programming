#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;






const ll mod = 1e9 + 7;

ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return powmod(a, mod - 2); // because mod is prime
}

int n;
ll m;
int a[100005], b[100005];

ll dfs(int i) {
    ll res;
    if (i == n) {
        res = 0;
    } else {
        if (a[i] != 0 && b[i] != 0) {
            if (a[i] == b[i]) {
                res = dfs(i+1);
            } else {
                res = a[i] > b[i];
            }
        } else if (a[i] == 0 && b[i] != 0) {
            res = (m - b[i])*inv(m) + dfs(i+1)*inv(m);
        } else if (a[i] != 0 && b[i] == 0) {
            res = (a[i] - 1)*inv(m) + dfs(i+1)*inv(m);
        } else { // both are 0
            res = (m-1)*inv(2*m) + dfs(i+1)*inv(m);
        }
    }
    res %= mod;
    return res;
}

void Main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll ans = dfs(0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
