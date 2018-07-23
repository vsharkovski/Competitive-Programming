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




// How-to:
// 1) construct adjacency matrix
// 2) check if graph is cyclic; if it is,
//    we cannot pick up the sticks as the task wants
//    let's say we have 1->2, 2->3, 3->1.
//    we need to pick up 1 before 2, and 2 before 3,
//    and 1 before one, which is impossible
// 3) use DFS to create a topological sorting;
//    (if edge u->v exists, u is before v in the sequence)

const int UNVISITED = -1, EXPLORED = 0, VISITED = 1;

int V, E;
vector<vi> adjlist;

bool hasCycle;

vi dfs_num, dfs_parent;
vi ts;

void dfs(int u) {
  if (hasCycle) return;
  dfs_num[u] = EXPLORED;
  
  for (int v : adjlist[u]) {
    if (dfs_num[v] == UNVISITED) { //Tree edge; EXPLORED -> UNVISITED
      dfs_parent[v] = u;
      dfs(v);
    } else if (dfs_num[v] == EXPLORED) { //Back edge; EXPLORED -> EXPLORED
      hasCycle = 1;
      return;      
    }
  }
  
  dfs_num[u] = VISITED;
  ts.push_back(u);
}


void SOLVE() {

  while (cin >> V >> E, V != 0 || E != 0) {

    adjlist.assign(V, vi());
  
    for (int i = 0; i < E; ++i) {
      int a, b;
      cin >> a >> b; //A is on top of B
      adjlist[a-1].push_back(b-1);
    }
    
    hasCycle = 0;
    ts.clear();
    dfs_num.assign(V, UNVISITED);
    dfs_parent.resize(V);
    
    for (int u = 0; u < V; ++u) {
      if (dfs_num[u] == UNVISITED) {
        dfs(u);
      }
    }
    
    if (hasCycle) {
      cout << "IMPOSSIBLE\n";
    } else {
      for (int i = V-1; i >= 0; --i) {
        cout << ts[i]+1 << '\n';
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














