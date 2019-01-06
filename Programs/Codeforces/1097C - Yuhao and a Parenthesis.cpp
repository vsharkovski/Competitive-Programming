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
  cin >> n;
  int numcorrect = 0;
  map<int, int> cntl, cntr;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int len = s.length();
    int xl = 0, xr = 0;
    int badl = 0, badr = 0;
    for (int j = len-1; j >= 0; --j) {
      if (s[j] == '(') --xr;
      else ++xr;
      if (xr < 0) {
        badr = 1;
        break;
      }
    }
    for (int j = 0; j < len; ++j) {
      if (s[j] == '(') ++xl;
      else --xl;
      if (xl < 0) {
        badl = 1;
      }
    }
//    cout << "s=" << s << " badl=" << badl << " badr=" << badr << " xl=" << xl << " xr=" << xr << "\n";
    if (badl == 0 && badr == 0) {
      ++numcorrect;
      if (numcorrect >= 2) {
        numcorrect -= 2;
        ++ans;
      }
    } else if (badl == 0) { // bad from right; xr < 0 somewhere; xl > 0
      if (cntr[xl] > 0) {
        --cntr[xl];
        ++ans;
      } else {
        ++cntl[xl];
      }
    } else if (badr == 0) { // bad from left; xl < 0 somewhere; xr > 0
      if (cntl[xr] > 0) {
        --cntl[xr];
        ++ans;
      } else {
        ++cntr[xr];
      }
    } else { // both bad

    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
