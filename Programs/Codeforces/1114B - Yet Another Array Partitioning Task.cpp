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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pi> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.emplace_back(x, i);
    }
    sort(a.begin(), a.end(), greater<pi>());
    vector<int> spec(n, 0);
    ll ans = 0;
    for (int i = 0; i < m*k; ++i) {
        ans += a[i].first;
        spec[a[i].second] = 1;
    }
    cout << ans << '\n';
    sort(a.begin(), a.end(), [&](pi &x, pi &y) {return x.second < y.second;});
    int c = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        if (spec[i]) {
            ++c;
            if (c == m && r+1 < k) {
                cout << i+1 << ' ';
                c = 0;
                ++r;
            }
        }
    }
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
