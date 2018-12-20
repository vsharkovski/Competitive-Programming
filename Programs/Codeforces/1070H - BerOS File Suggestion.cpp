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
map<string, pair<int, string>> m;

void _SOLVE_() {
  cin >> n;
  for (int si = 0; si < n; ++si) {
    string s;
    cin >> s;
    int len = s.length();
    set<string> done;
    for (int i = 0; i < len; ++i) {
      string t = "";
      for (int j = i; j < len; ++j) {
        t += s[j];
        if (done.count(t)) continue;
        done.insert(t);
        auto it = m.find(t);
        if (it != m.end()) {
          it->second.first += 1;
        } else {
          m[t] = {1, s};
        }
      }
    }
  }
  int q;
  cin >> q;
  for (int qi = 0; qi < q; ++qi) {
    string s;
    cin >> s;
    auto it = m.find(s);
    if (it != m.end()) {
      cout << it->second.first << " " << it->second.second << "\n";
    } else {
      cout << "0 -\n";
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
