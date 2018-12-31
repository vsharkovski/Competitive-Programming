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




int N;
double dp[1<<16];
double dist[16][16];

double F(int m) {
  double& res = dp[m];
  if (res != -1) {
    return res;
  }
  if (m == (1 << (2*N)) - 1) {
    return res = 0;
  }
  res = 1e9;
  for (int i = 0; i < 2*N; ++i) {
    if (m & (1 << i)) continue;
    for (int j = i+1; j < 2*N; ++j) {
      if (m & (1 << j)) continue;
      res = min(res, dist[i][j] + F(m | (1 << i) | (1 << j)));
    }
  }
  return res;
}

void Solution() {
  int Case = 1;
  cout << setprecision(2) << fixed;
  while (cin >> N, N != 0) {
    double x[16], y[16];
    for (int i = 0; i < 2*N; ++i) {
      string s;
      cin >> s >> x[i] >> y[i];
      for (int j = 0; j < i; ++j) {
        dist[i][j] = dist[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
      }
    }
    fill(dp, dp+(1<<16), -1);
    double res = F(0);
    cout << "Case " << Case++ << ": " << res << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}



/**
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




int N;
double dp[1<<16];
double dist[16][16];

void Solution() {
  int Case = 1;
  cout << setprecision(2) << fixed;
  while (cin >> N, N != 0) {
    double x[16], y[16];
    for (int i = 0; i < 2*N; ++i) {
      string s;
      cin >> s >> x[i] >> y[i];
      for (int j = 0; j < i; ++j) {
        dist[i][j] = dist[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
      }
    }
    fill(dp, dp+(1<<(2*N)), 1e9);
    dp[0] = 0;
    for (int m = 0; m < (1 << (2*N)); ++m) {
      for (int i = 0; i < 2*N; ++i) {
        if (m & (1 << i)) continue;
        for (int j = i+1; j < 2*N; ++j) {
          if (m & (1 << j)) continue;
          int m1 = m | (1 << i) | (1 << j);
          dp[m1] = min(dp[m1], dp[m] + dist[i][j]);
        }
      }
    }
    double res = dp[(1 << (2*N)) - 1];
    cout << "Case " << Case++ << ": " << res << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}
**/
