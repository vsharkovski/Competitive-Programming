#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





const ll mod = 998244353;

int n;
vector<int> a;
map<int, int> nxt;

void Main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    nxt[a[i]] = i + 1;
  }
  ll ans = 1;
  int i = 0;
  while (i < n) {
    if (i > 0) {
      ans = (ans * 2) % mod;
    }
    int nxti = nxt[a[i]];
    for (int j = i; j < nxti; ++j) {
      nxti = max(nxti, nxt[a[j]]);
    }
    i = nxti;
  }
  cout << ans << '\n';
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
