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

  int n;
  double r;
  double xcoords[1002];
  vector<pair<double, double>> placed;

  cin >> n >> r;
  for (int i = 0; i < n; ++i) {
    cin >> xcoords[i];
    placed.emplace_back(xcoords[i], -r);
  }

  cout << setprecision(15) << fixed;
  for (int i = 0; i < n; ++i) {
    double x2 = xcoords[i], y2 = 0;
    for (auto& p : placed) {
      double x1 = p.first, y1 = p.second;
      if (abs(x1 - x2) <= 2*r) {
        double y = y1 + sqrt( (2*r)*(2*r) - (x2 - x1)*(x2 - x1) );
        y2 = max(y2, y);
      }
    }
    placed.emplace_back(x2, y2);
    cout << y2 << " ";
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
