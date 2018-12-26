#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





void _SOLVE_() {

    int n, k;
    ll cnt[200005];
    int minh = 1e9, maxh = 0;

    fill(cnt, cnt+200003, 0);
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        ++cnt[h];
        minh = min(h, minh);
        maxh = max(h, maxh);
    }

    int ans = 0;
    ll curr = 0;

    for (int h = maxh; h >= minh+1; --h) {
        if (curr + cnt[h] > k) {
            curr = 0;
            ++ans;
        }
        curr += cnt[h];
        cnt[h-1] += cnt[h];
    }
    if (curr > 0) {
        ++ans;
    }

    cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
