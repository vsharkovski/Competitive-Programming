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






const int INF = 2E9;

int V, E;
vector<vi> adjlist;

bool bfs(int s) { //bipartite check
  queue<int> q;
  q.push(s);
  
  vi color(V, INF);
  color[s] = 0;
  
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adjlist[u]) { 
      if (color[v] == INF) {
        color[v] = !color[u];
        q.push(v);
      } else if (color[v] == color[u]) {
        return false;
      }
    }
  }
  
  return true;
}

void SOLVE() {

  while (cin >> V >> E, V != 0) {
  
    adjlist.assign(V, vi());
    for (int i = 0; i < E; ++i) {
      int a, b;
      cin >> a >> b;
      adjlist[a].push_back(b);
      adjlist[b].push_back(a);
    }
    
    bool ans = bfs(0);
    if (!ans) cout << "NOT ";
    cout << "BICOLORABLE.\n";
  
  
  
  
  
  
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














