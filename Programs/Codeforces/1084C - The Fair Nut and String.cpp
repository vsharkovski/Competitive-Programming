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


const ll mod = 1000000007;

int n;
string s;

void _SOLVE_() {
  cin >> s;
  s += 'b';
  n = s.length();
  ll ans = 1;
  ll curr = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      ++curr;
    } else if (s[i] == 'b') {
      ans *= (curr + 1);
      ans %= mod;
      curr = 0;
    }
  }
  ans -= 1;
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
