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



int UNVISITED = -1, EXPLORED = 0, VISITED = 1;


int V;
vector<vi> adjlist;
vi dfs_num, dfs_parent;

void graphCheck(int u) {
  dfs_num[u] = EXPLORED;
  for (int v : adjlist[u]) {
    if (dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      graphCheck(v);
    }
    else if (dfs_num[v] == EXPLORED) {
      if (v == dfs_parent[u]) {
        cout << " Two ways (" << u << ", " << v << ")-(" << v << ", " << u << ")\n";
      } else {
        cout << " Back edge (" << u << ", " << v << ") (Cycle)\n";
      }
    }
    else if (dfs_num[v] == VISITED) {
      cout << " Forward/cross edge (" << u << ", " << v << ")\n";
    }
  }
  dfs_num[u] = VISITED;
}



void SOLVE() {

  cin >> V;
  adjlist.assign(V, vi());
  dfs_num.assign(V, UNVISITED);
  dfs_parent.assign(V, 0);

  int x, y;
  while (cin >> x >> y) {
    adjlist[x].push_back(y);
  }
  
  int numComp = 0;
  
  bool Ex4271 = 1;
  
  if (Ex4271) {
    graphCheck(0);
  } else {
    for (int i = 0; i < V; ++i) {
      if (dfs_num[i] == UNVISITED) {
        cout << "Component " << ++numComp << ":\n";
        graphCheck(i);
      }
    }
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











