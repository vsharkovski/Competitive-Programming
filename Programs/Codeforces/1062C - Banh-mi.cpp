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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



const ll mod = 1e9 + 7;

void _SOLVE_() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  vi c0(n+2), c1(n+2);
  c0[0] = c1[0] = 0;
  for (int i = 1; i <= n; ++i) {
    c0[i] = c0[i-1];
    c1[i] = c1[i-1];
    if (s[i-1] == '0') ++c0[i];
    else ++c1[i];
  }

  vl pow2(100005);
  pow2[0] = 1;
  for (int i = 1; i <= 100002; ++i) {
    pow2[i] = (pow2[i-1] * 2) % mod;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    int num1 = c1[r] - c1[l-1];
    int num0 = c0[r] - c0[l-1];
    ll res = (pow2[num1] - 1) * pow2[num0];
    res %= mod;
    cout << res << endl;
  }
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
