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



struct Edge {
  int u, v, w;
  Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
  Edge() {}
  bool operator < (const Edge& rhs) const {
    return w > rhs.w;
  }
};

int V, K;
int dist[101][101];
priority_queue<Edge> pq;

void apsp() {
  for (int k = 1; k <= V; ++k)
    for (int u = 1; u <= V; ++u)
      for (int v = 1; v <= V; ++v)
        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
}

void _SOLVE_() {
  int L;
  cin >> L;
  vi ans;
  for (int LN = 1; LN <= L; ++LN) {
    cin >> V >> K;
    while (!pq.empty())
      pq.pop();
    for (int u = 1; u <= V; ++u)
      for (int v = 1; v <= V; ++v)
        dist[u][v] = 1e9;
    for (int u = 1; u <= V; ++u) {
      for (int v = u+1; v <= V; ++v) {
        int w;
        cin >> w;
        pq.emplace(u, v, w);
      }
    }
    while (!pq.empty()) {
      Edge top = pq.top();
      pq.pop();
      if (dist[top.u][top.v] == top.w) {
        continue; //problem yok
      } else if (dist[top.u][top.v] > top.w && K > 0) {
        //we must use this edge, afterwards we relax all shortest paths
        dist[top.u][top.v] = dist[top.v][top.u] = top.w;
        apsp();
        --K;
      } else { //impossible (dist < w) or (dist > w and can't use edge because K = 0)
        ans.push_back(LN);
        break;
      }
    }
  }
  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";
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
