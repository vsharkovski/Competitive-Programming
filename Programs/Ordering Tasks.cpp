#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
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

vi dfs_num;
vi ts;

void dfs(int u) {
  dfs_num[u] = 1;
  for (int v : adjlist[u]) {
    if (dfs_num[v] == -1) {
      dfs(v);
    }
  }
  ts.push_back(u);
}

void SOLVE() {

  while (cin >> V >> E, V != 0 || E != 0) {

    
    if (E == 0) {
      for (int u = 1; u < V; ++u)
        cout << u << ' ';
      cout << V << '\n';
      return;
    }
  
    adjlist.assign(V, vi());
    dfs_num.assign(V, -1);
    
    for (int i = 0; i < E; ++i) {
      int a, b;
      cin >> a >> b;
      adjlist[a-1].push_back(b-1);
    }
  
    ts.clear();
    
    for (int u = 0; u < V; ++u) {
      if (dfs_num[u] == -1) {
        dfs(u);
      }
    }
    
    reverse(all(ts));
    
    cout << ts[0]+1;
    for (int i = 1; i < V; ++i) {
      cout << ' ' << ts[i]+1;
    }
    
    cout << '\n';
  
  
  
  
  }





}












int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  SOLVE();
}














