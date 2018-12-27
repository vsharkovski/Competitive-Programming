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




inline string tostr(int msk) {
  string res = "";
  for (int i = 0; i < 26; ++i) {
    if (msk & (1 << i)) res += '1';
    else res += '0';
  }
  return res;
}

void _SOLVE_() {

  int n;
  ll ans = 0;
  map<int, int> cnt;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int msk = 0;
    for (char ch : s) {
      int x = ch - 'a';
      msk ^= (1 << x);
    }
    ans += cnt[msk];
    ++cnt[msk];
    for (int x = 0; x < 26; ++x) {
        ++cnt[msk ^ (1 << x)];
    }
  }

  cout << ans << endl;;

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
