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







void _SOLVE_() {
  int n;
  cin >> n;
  vi pwr(1000005, 0);
  int maxpwr = 0;
  for (int x = 2; x <= 1000; ++x) {
    while (n % x == 0) {
      ++pwr[x];
      maxpwr = max(pwr[x], maxpwr);
      n /= x;
    }
  }
  if (n > 0) {
    ++pwr[n];
    maxpwr = max(1, maxpwr);
  }
  while (maxpwr == 0 || (maxpwr & (maxpwr - 1)) > 0) {
    ++maxpwr;
  }
  int moves = 0;
  ll res = 1;
  for (int x = 2; x <= 1000000; ++x) {
    if (pwr[x] > 0 && pwr[x] < maxpwr) {
      moves = 1;
    }
    if (pwr[x] > 0) {
      res *= x;
    }
  }
  while (maxpwr > 1) {
    ++moves;
    maxpwr >>= 1;
  }
  cout << res << " " << moves << endl;


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
