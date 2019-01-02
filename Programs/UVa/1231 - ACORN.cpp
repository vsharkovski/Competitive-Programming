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






void Solution() {
  int T;
  cin >> T;
  while (T--) {

    int nt, mh, f;
    cin >> nt >> mh >> f;

    vector<vector<int>> acorn(nt+2, vector<int>(mh+2, 0));

    for (int i = 0; i < nt; ++i) {
      int a, h;
      cin >> a;
      while (a--) {
        cin >> h;
        ++acorn[i][h];
      }
    }

    for (int h = mh; h >= 0; --h) {
      int bestifjumped = 0;
      // you could replace the following loop with a dp table
      // dp[h+f] = bestifjumped at height h
      // dp[h] = max( acorn[i][h] ), i = 0, 1, ..., nt-1
      for (int i = 0; i < nt; ++i) {
        if (h + f <= mh) {
          int ifjumped = acorn[i][h+f];
          bestifjumped = max(bestifjumped, ifjumped);
        }
      }
      for (int i = 0; i < nt; ++i) {
        int ifstood = acorn[i][h+1];
        acorn[i][h] += max(ifstood, bestifjumped);
      }
    }

    int ans = 0;
    for (int i = 0; i < nt; ++i) {
      ans = max(ans, acorn[i][0]);
    }

    cout << ans<< '\n';

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
