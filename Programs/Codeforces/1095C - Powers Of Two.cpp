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

  int n, k;
  cin >> n >> k;

  vi ans1;
  for (int i = 1; i <= n; i <<= 1) {
    if ((n & i) != 0) {
      ans1.push_back(i);
    }
  }

  if (ans1.size() > k) {
    cout << "NO";
    return;
  }
  if (ans1.size() == k) {
    cout << "YES\n";
    for (int x : ans1) cout << x << " ";
    return;
  }

  vi ans2;
  k -= ans1.size();
  for (int I = 0; I < 32 && k > 0; ++I) {
    for (int i = 0; i < ans1.size(); ++i) {
      if (k > 0) {
        if (ans1[i] >= 2) {
          int y = ans1[i];
          ans2.push_back(ans1[i]/2);
          ans2.push_back(ans1[i]/2);
          --k;
        } else {
          ans2.push_back(ans1[i]);
        }
      } else {
        ans2.push_back(ans1[i]);
      }
    }
//    for (int y : ans2) {
//      cout << y << " ";
//    }cout << endl;
    ans1.clear();
    swap(ans1, ans2);
  }

  if (k == 0) {
    cout << "YES\n";
    for (int x : ans1) {
      cout << x << " ";
    }
  } else {
    cout << "NO\n";
  }
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
