#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





void Main() {
    ll n, b;
    cin >> n >> b;
    ll ans = 1e18;
    for (ll p = 2; p <= b; ++p) {
        if (p * p > b) p = b;
        if (b % p == 0) {
            ll y = 0;
            while (b % p == 0) {
                ++y;
                b /= p;
            }
            ll x = 0;
            ll fuck  = 1;
            while (fuck <= n / p) {
                fuck *= p;
                x += n / fuck;
            }
            ans = min(ans, x / y);
        }
    }
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
