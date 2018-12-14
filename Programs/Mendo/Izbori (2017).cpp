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



int N, M;
bool mat[32][32];
vi triples[32];

int dfs(int i, int msk) {
  int res = 0;
  if (i == N) {
    res += 1;
  } else if (triples[i].empty()) {
    res += 2 * dfs(i+1, msk);
    //actually dfs(i+1, msk) + dfs(i+1, msk | (1 << i))
    //but it doesn't matter
  } else {
    res += dfs(i+1, msk); //don't turn on
    bool ok = 1;
    for (int b : triples[i]) {
      if ((msk & b) == b) {
        ok = 0;
        break;
      }
    }
    if (ok) { //if it is legal to turn on
      res += dfs(i+1, msk | (1 << i));
    }
  }
  return res;
}

void _SOLVE_() {
  cin >> N >> M;
  memset(mat, 0, sizeof(mat));
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    mat[u][v] = mat[v][u] = 1;
  }
  for (int u = 0; u < N; ++u) {
    for (int v = u+1; v < N; ++v) {
      if (mat[u][v] == 0) continue;
      for (int k = v+1; k < N; ++k) {
        if (mat[u][k] == 0 || mat[v][k] == 0) continue;
        triples[u].push_back((1 << v) | (1 << k));
        triples[v].push_back((1 << u) | (1 << k));
        triples[k].push_back((1 << u) | (1 << v));
      }
    }
  }
  int ans = dfs(0, 0);
  cout << ans << endl;
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
