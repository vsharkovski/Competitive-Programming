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

  string s;
  cin >> s;

  int n = s.length();
  vector<vi> seqs;
  set<int> good, bad;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      if (good.empty()) {
        cout << -1;
        return;
      } else {
        int p = *good.begin();
        good.erase(good.begin());
        seqs[p].push_back(i);
        bad.insert(p);
      }
    } else {
      if (bad.empty()) {
        good.insert(seqs.size());
        seqs.push_back(vi());
        seqs.back().push_back(i);
      } else {
        int p = *bad.begin();
        bad.erase(bad.begin());
        seqs[p].push_back(i);
        good.insert(p);
      }
    }
  }

  if (!bad.empty()) {
    cout << -1;
    return;
  }

  cout << seqs.size() << endl;
  for (vi& v : seqs) {
    cout << v.size();
    for (int x : v) {
      cout << " " << x+1;
    }
    cout << endl;
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
