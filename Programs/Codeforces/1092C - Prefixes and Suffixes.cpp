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
string affixes[210];
int status[210];

void _SOLVE_() {
  cin >> n;
  int o1 = -1, o2 = -1;
  for (int i = 0; i < 2*n - 2; ++i) {
    cin >> affixes[i];
    if (affixes[i].length() == n-1) {
      if (o1 == -1) {
        o1 = i;
      } else {
        o2 = i;
      }
    }
  }
  for (int I = 0; I < 2; ++I) {
    for (int i = 0; i < 2*n - 2; ++i) {
      status[i] = 0;
    }
    string s = affixes[o1] + affixes[o2][n-2];
    string pref = "", suff = "";
    bool bad = 0;
    for (int i = 0; i < n-1; ++i) {
      pref += s[i];
      bool found = 0;
      for (int j = 0; j < 2*n - 2; ++j) {
        if (status[j] == 0 && affixes[j] == pref) {
          status[j] = 1;
          found = 1;
          break;
        }
      }
      if (!found) {
        bad = 1;
        break;
      }
    }
    for (int i = 0; i < n-1; ++i) {
      suff = s[n-1-i] + suff;
      bool found = 0;
      for (int j = 0; j < 2*n - 2; ++j) {
        if (status[j] == 0 && affixes[j] == suff) {
          status[j] = 2;
          found = 1;
          break;
        }
      }
      if (!found) {
        bad = 1;
        break;
      }
    }
    if (!bad) {
      for (int i = 0; i < 2*n - 2; ++i) {
        if (status[i] == 1) {
          cout << "P";
        } else {
          cout << "S";
        }
      }
      break;
    }
    swap(o1, o2);
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
