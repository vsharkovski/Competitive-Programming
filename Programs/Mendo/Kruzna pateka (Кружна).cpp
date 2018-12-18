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




#define mdn(x) ((x) + (N)) % (N)

void _SOLVE_() {

  int N, S, T, R0, P1, P2, M;
  cin >> N >> S >> T >> R0 >> P1 >> P2 >> M;

  vector<int> R(N);
  R[0] = R0;
  for (int i = 1; i < N; ++i) {
    R[i] = (R[i-1] * P1 + P2) % M;
  }

  vector<int> dist(N, -1);
  queue<int> q;
  int lb = S, rb = S;

  dist[S] = 0;
  q.push(S);
  while (!q.empty()) {
    int i = q.front();
    q.pop();

    int mi = mdn(i);
    for (int j = i - R[mi]; j < lb; ++j) {
      int mj = mdn(j);
      if (dist[mj] != -1) break;
      dist[mj] = dist[mi] + 1;
      q.push(j);
    }
    for (int j = i + R[mi]; j > rb; --j) {
      int mj = mdn(j);
      if (dist[mj] != -1) break;
      dist[mj] = dist[mi] + 1;
      q.push(j);
    }

    lb = min(lb, i - R[mi]);
    rb = max(rb, i + R[mi]);
  }

  cout << dist[T] << endl;
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
