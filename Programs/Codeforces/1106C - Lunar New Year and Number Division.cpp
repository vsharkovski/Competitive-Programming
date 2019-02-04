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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = 0; i < n/2; ++i) {
        ll s = a[i] + a[n-i-1];
        sum += s*s;
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
