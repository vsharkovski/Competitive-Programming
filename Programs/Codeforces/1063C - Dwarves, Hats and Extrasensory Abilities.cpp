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



bool ask(int x, int y) {
  string s;
  cout << x << " " << y << "\n";
  cout.flush();
  cin >> s;
  return s == "black";
}

const int top = 1000000000;

void _SOLVE_() {

  int n;
  cin >> n;

  --n;
  bool left = ask(0, top/2);

  int l = 1, r = top, mid, vl = 0, vr = top;
  while (n--) {
    mid = (l + r) / 2;
    if (ask(mid, top/2) == left) {
      vl = max(vl, mid);
      l = mid+1;
    } else {
      vr = min(vr, mid);
      r = mid-1;
    }
  }

  cout << vl << " 0 " << vr << " " << top << "\n";
  cout.flush();

}

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
