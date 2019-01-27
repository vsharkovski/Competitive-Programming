#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





void Main() {
  int n, k;
  cin >> n >> k;
  ll a[200005];
  char b[200005];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  ll dmg = 0;
  int currlen = 1;
  vector<pair<char, int>> segs;
  for (int i = 1; i < n; ++i) {
    if (b[i] != b[i-1]) {
      segs.emplace_back(b[i-1], currlen);
      currlen = 1;
    } else {
      ++currlen;
    }
  }
  segs.emplace_back(b[n-1], currlen);
  int i = 0;
  for (pair<char, int>& s : segs) {
    int len = s.second;
    vector<ll> vals;
    for (int j = i; j < i+len; ++j) {
      vals.emplace_back(a[j]);
    }
    sort(vals.begin(), vals.end(), greater<ll>());
    for (int j = 0; j < min(k, (int)vals.size()); ++j) {
      dmg += vals[j];
    }
    i += len;
  }
  cout << dmg << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
