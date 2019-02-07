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





int n, k;
ll A, B;
vector<int> a;

ll rec(ll L, ll R) {
    if (L > R) {
        return 0;
    }
    auto lit = lower_bound(a.begin(), a.end(), L);
    auto rit = prev(upper_bound(a.begin(), a.end(), R));
    int cnt = max(0, distance(a.begin(), rit) - distance(a.begin(), lit) + 1);
    if (cnt == 0) {
        return A;
    } else {
        ll res = B * cnt * (R - L + 1);
        if (L < R) {
            ll m = (L + R) / 2;
            ll opt = rec(L, m) + rec(m+1, R);
            res = min(res, opt);
        }
        return res;
    }
}

void Main() {
    cin >> n >> k >> A >> B;
    a.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = rec(1, 1 << n);
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
