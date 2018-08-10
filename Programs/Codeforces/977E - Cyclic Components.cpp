#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int V, E;
vector<vi> adjlist;

int ans;
vi dfs_num;

bool curr;

void dfs(int u) {
  dfs_num[u] = 1;
  if (curr && adjlist[u].size() != 2) curr = 0;
  for (int v : adjlist[u]) {
    if (dfs_num[v] == -1) {
      dfs(v);
    }
  }
}

void MAIN() {

  cin >> V >> E;
  adjlist.assign(V, vi());
  dfs_num.assign(V, -1);
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    adjlist[u-1].push_back(v-1);
    adjlist[v-1].push_back(u-1);
  }

  ans = 0;

  for (int u = 0; u < V; ++u) {
    if (dfs_num[u] == -1) {
      curr = 1;
      dfs(u);
      if (curr) ++ans;
    }
  }

  cout << ans << endl;





}




int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  MAIN();
}








