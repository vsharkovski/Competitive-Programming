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
  int T;
  cin >> T;
  string s;
  while (T--) {
    int cnt[200] = {};
    cin >> s;
    int numdiff = 0;
    for (char ch : s) {
      if (cnt[ch] == 0) {
        ++numdiff;
      }
      ++cnt[ch];
    }
    if (numdiff == 1) {
      cout << -1 << endl;
    } else {
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        while (cnt[ch]--) {
          cout << ch;
        }
      }
      cout << endl;
    }
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
