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
  cin >> n >> k;

  vpi pairs(n);
  vi cnt(n+1, 0);
  int numok = 0;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    pairs[i].first = a;
    ++cnt[a];
    if (cnt[a] == 1) {
      ++numok;
    }
  }
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    pairs[i].second = b;
  }
  sort(pairs.begin(), pairs.end(), [&](pi &x, pi &y){
    return x.second < y.second;
  });

  ll ans = 0;
  int ei = 1; //for cnt = 0

  for (int pi = 0; pi < n && ei <= n && numok < k; ++pi) {
    int a = pairs[pi].first, b = pairs[pi].second;
    if (cnt[a] == 1) continue;
    while (ei <= n && cnt[ei] > 0) {
      ++ei;
    }
    if (ei > n) break;
    ++cnt[ei];
    --cnt[a];
    ans += b;
    ++numok;
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
