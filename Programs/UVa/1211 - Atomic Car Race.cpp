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



int n;
int a[105];
double b, r, v, e, f;

double T[10005];
double dp[105];

void _SOLVE_() {
  cout << setprecision(4) << fixed;
  while (cin >> n, n != 0) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    cin >> b >> r >> v >> e >> f;
    T[0] = 0 >= r ? 1/(v - e*(0 - r)) : 1/(v - f*(r - 0));
    for (int x = 1; x <= a[n]; ++x) {
      T[x] = T[x-1] + (x >= r ? 1/(v - e*(x - r)) : 1/(v - f*(r - x)));
    }
    fill(dp, dp+n+1, 1e9);
    dp[0] = 0;
    a[0] = 0;
    for (int i = 1; i <= n; ++i){
      for (int j = 0; j < i; ++j) {
        dp[i] = min(dp[i], dp[j] + T[a[i] - a[j] - 1] + b);
      }
    }
    dp[n] -= b;
    cout << dp[n] << "\n";
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
