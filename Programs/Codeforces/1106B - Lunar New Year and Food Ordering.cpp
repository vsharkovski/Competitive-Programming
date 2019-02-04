#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




void Main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), [&](int i, int j){
        return c[i] == c[j] ? i < j : c[i] < c[j];
    });
    int idx = 0;
    while (m--) {
        ll t, d;
        cin >> t >> d;
        --t;
        ll cost = 0;
        if (a[t] < d) {
            d -= a[t];
            cost += c[t] * a[t];
            a[t] = 0;
            while (d > 0 && idx < n) {
                if (a[v[idx]] < d) {
                    cost += c[v[idx]] * a[v[idx]];
                    d -= a[v[idx]];
                    a[v[idx]] = 0;
                    ++idx;
                } else {
                    a[v[idx]] -= d;
                    cost += c[v[idx]] * d;
                    d = 0;
                }
            }
            if (d != 0) {
                cost = 0;
            }
        } else {
            a[t] -= d;
            cost += c[t] * d;
            d = 0;
        }
        cout << cost << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
