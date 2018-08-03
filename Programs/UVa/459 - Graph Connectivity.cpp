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
const int G_V = 1, G_U = -1; //graph visited constant, graph unvisited constant




// the largest node name is Z, all nodes are A-Z
// V <= 26

int V;
vector<vi> adjlist;
vi dfs_num;

void dfs(int u) {
  dfs_num[u] = G_V;
  for (int v : adjlist[u]) {
    if (dfs_num[v] == G_U) {
      dfs(v);
    }
  }
}


void SOLVE() {

  int T;
  cin >> T;
  while (T--) {
  
    char maxch;
    cin >> maxch;
    V = maxch - 'A' + 1;
    
    adjlist.assign(V, vi());
    
    cin.ignore();
    string line = "";
    while (getline(cin, line) && line != "") {
      int x = line[0]-'A', y = line[1]-'A';
      adjlist[x].push_back(y);
      adjlist[y].push_back(x); //undirected graph!
    }
    
    int numCC = 0;
    dfs_num.assign(V, G_U);
    for (int i = 0; i < V; ++i) {
      if (dfs_num[i] == G_U) {
        ++numCC;
        dfs(i);
      }
    }
    
    cout << numCC << '\n';
    if (T > 0) cout << '\n';
  
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















