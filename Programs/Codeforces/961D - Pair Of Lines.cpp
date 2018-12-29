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
ll x[100005], y[100005];

bool collinear(int a, int b, int c) {
  // a, b, c are collinear if cross product of (b - a) * (c - a) is 0
  ll x1 = x[b] - x[a];
  ll y1 = y[b] - y[a];
  ll x2 = x[c] - x[a];
  ll y2 = y[c] - y[a];
  return x1*y2 - x2*y1 == 0;
}


void _SOLVE_() {

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  if (n <= 2) {
    cout << "YES\n";
    return;
  }

  bool used[100005];
  int starts[3] = {0, 1, 2};

  do {
    memset(used, 0, sizeof(used));
    // first line
    int i1 = starts[0], i2 = starts[1];
    used[i1] = used[i2] = 1;
    int numunused = n - 2;
    for (int i = 0; i < n; ++i) {
      if (used[i] == 0 && collinear(i1, i2, i)) {
        used[i] = 1;
        --numunused;
      }
    }
    // second line
    i1 = -1, i2 = -1;
    for (int i = 0; i < n; ++i) {
      if (used[i] == 0) {
        if (i1 == -1) {
          i1 = i;
          used[i] = 1;
          --numunused;
        } else if (i2 == -1) {
          i2 = i;
          used[i] = 1;
          --numunused;
        } else if (collinear(i1, i2, i)) {
          used[i] = 1;
          --numunused;
        }
      }
    }
    if (numunused == 0) {
      cout << "YES\n";
      return;
    }
  } while (next_permutation(starts, starts+3));

  cout << "NO\n";

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
