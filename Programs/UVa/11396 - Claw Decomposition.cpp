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

int V;
vector<vi> adjlist;
vi color;
bool isBipartite;

void bfs(int s) {
  queue<int> q;
  q.push(s);
  color[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adjlist[u]) {
      if (color[v] == INF) {
        color[v] = 1 - color[u];
        q.push(v);
      } else if (color[v] == color[u]) {
        isBipartite = false;
        return;
      }
    }
  }
}


void SOLVE() {
  
  while (cin >> V, V != 0) {
    adjlist.assign(V, vi());
    int a, b;
    while (cin >> a >> b, a != 0 && b != 0) {
      adjlist[a-1].push_back(b-1);
      adjlist[b-1].push_back(a-1);
    }
    
    color.assign(V, INF);
    isBipartite = true;
    
    for (int u = 0; u < V && isBipartite; ++u) {
      if (color[u] == INF) {
        bfs(u);
      }
    }
  
    if (isBipartite) cout << "YES\n"; else cout << "NO\n";
  
  
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














