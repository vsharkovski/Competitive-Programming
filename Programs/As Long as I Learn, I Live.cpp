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

vi value;


void SOLVE() {
  int T;
  cin >> T;
  for (int CT = 1; CT <= T; ++CT) {
  
    cin >> V >> E;
    value.resize(V);
    adjlist.assign(V, vi());
    
    for (int i = 0; i < V; ++i) {
      cin >> value[i];
    }
    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      adjlist[u].push_back(v);
    }
  
    int cnt = 0;
    int u = 0;
    int nextu, maxi;
    
    while (adjlist[u].size() > 0) {
      maxi = -1;
      for (int v : adjlist[u]) {
        if (value[v] > maxi) {
          nextu = v;
          maxi = value[v];
        }
      }
      cnt += maxi;
      u = nextu;
    }
  
    cout << "Case " << CT << ": " << cnt << " " << u << '\n';
  
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














