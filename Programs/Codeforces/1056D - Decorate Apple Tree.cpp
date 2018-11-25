#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;



int n;
vector<vector<int>> G;
vector<int> numleafs;

int dfs(int u, int p) {
  if (G[u].size() == 1 && G[u][0] == p) {
    numleafs[u] = 1;
  } else {
    for (int v : G[u]) {
      if (v != p) {
        numleafs[u] += dfs(v, u);
      }
    }
  }
//  cout << "numleafs[" << u << "] = " << numleafs[u] << endl;
  return numleafs[u];
}

void Solve() {
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  G.assign(n+1, vector<int>());
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    G[i].push_back(p);
    G[p].push_back(i);
  }
  numleafs.resize(n+1);
  dfs(1, 0);
  sort(numleafs.begin()+1, numleafs.end());
  for (int k = 1; k <= n; ++k) {
    cout << numleafs[k] << " ";
  }
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
