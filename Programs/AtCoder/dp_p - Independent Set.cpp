#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;



typedef pair<ll, ll> pl;
const ll mod = 1e9 + 7;

int V;
vector<int> G[100000];

pl dfs(int u, int p) {
  ll w = 1, b = 1;
  for (int v : G[u]) {
    if (v != p) {
      pl res = dfs(v, u);
      w *= (res.first + res.second) % mod;
      w %= mod;
      b *= res.first;
      b %= mod;
    }
  }
//  cout << "u=" << u << " w=" << w << " b=" << b << '\n';
  return pl(w, b);
}

void Main() {
  cin >> V;
  for (int i = 0; i < V-1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  pl res = dfs(0, -1);
  ll ans = (res.first + res.second) % mod;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
