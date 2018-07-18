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



// Bipartite graph check using DFS (exercise 4.2.7 of Competitive Programming 3)
// V vertexes, numbered 0 to V-1

// Example inputs

/*
5
0 1
0 4
1 3
4 2
2 3
*/

/*
5
0 1
0 4
1 3
4 2
*/

int V;
vector<vi> adjlist;

vi color;

bool notBipartite = 0;

void dfs(int u, bool b) {
  if (notBipartite) return;
  
  color[u] = b;
  
  for (int v : adjlist[u]) {
    if (color[v] == -1) {
      dfs(v, !b);
    } else if (color[v] == color[u]) {
      notBipartite = 1;
      return;    
    }
  }
}


void SOLVE() {

  cin >> V;
  color.assign(V, -1);
  adjlist.assign(V, vi());
  
  int x, y;
  while (cin >> x >> y) {
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
  }

  dfs(0, 0);
  if (notBipartite) cout << "no\n"; else cout << "yes\n";
  
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











