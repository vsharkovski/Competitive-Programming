#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




vector<vector<int>> G;
vector<int> realname;
vector<int> dist;

void dfs(int u, int d) {
  dist[u] = d;
  for (int v : G[u])
    if (dist[v] == -1)
      dfs(v, d+1);
}

void Solve() {
  int A, B, n;
  string s;
  cin >> A >> B >> s;

  n = s.length();
  G.assign(n+1, vector<int>());
  realname.assign(n+1, -1);

  int vtx = 0;
  realname[0] = 0;
  stack<int> Us;
  Us.push(0);

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') {
      G[vtx].push_back(i+1);
      G[i+1].push_back(vtx);
      vtx = i+1;
      Us.push(vtx);
    } else {
      Us.pop();
      vtx = Us.top();
    }
    realname[i+1] = vtx;
  }

  dist.assign(n, -1);
  dfs(realname[A], 0);
  cout << dist[realname[B]] << endl;
}



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
