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




const ll mod = 998244353;

vector<ll> fact;

ll f(ll n) {
  return n == 1 ? 1 : (fact[n] + (n * (f(n-1) - 1)) % mod) % mod;
}

void _SOLVE_() {

  fact.resize(1000001);
  fact[0] = 1;
  for (ll x = 1; x <= 1000000; ++x) {
    fact[x] = (fact[x-1] * x) % mod;
  }

  ll n;
  cin >> n;

  cout << f(n) << '\n';


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
