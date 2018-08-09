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




int V, E, s;
vector<vi> adjlist;

bitset<5001> status1, status2;

void dfs1(int u) {
  status1.set(u);
  for (int v : adjlist[u]) {
    if (!status1[v]) {
      dfs1(v);
    }
  }
}

int dfs2cnt;

void dfs2(int u) {
  status2.set(u);
  ++dfs2cnt;
  for (int v : adjlist[u]) {
    if (!status1[v] && !status2[v]) {
      dfs2(v);
    }
  }
}

void MAIN() {

  cin >> V >> E >> s;
  --s;
  adjlist.assign(V, vi());
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    adjlist[u-1].push_back(v-1);
  }

  dfs1(s);

  vector<ii> kandidati;
  for (int u = 0; u < V; ++u) {
    if (!status1[u]) {
      status2.reset();
      dfs2cnt = 0;
      dfs2(u);
      kandidati.push_back(ii(u, dfs2cnt));
    }
  }

  sort(all(kandidati), [](ii &x, ii &y) {
    return x.second > y.second;
  });

  int cnt = 0;
  for (ii k : kandidati) {
    if (!status1[k.first]) {
      ++cnt;
      dfs1(k.first);
    }
  }

  cout << cnt << endl;

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








