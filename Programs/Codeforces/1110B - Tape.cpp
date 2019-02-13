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
    int b[100005];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int ans = n;
    vector<int> d;
    for (int i = 1; i < n; ++i) {
        d.push_back(b[i] - b[i-1] - 1);
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < n-k; ++i) {
        ans += d[i];
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
