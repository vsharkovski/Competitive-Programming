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



struct Station {
  int x, y;
  pair<ii, ii> dest; // id, dist
  Station() {
    x = 0, y = 0;
    dest.first = dest.second = ii(0, 2e9);
  }
};

inline int distsq(Station &a, Station &b) {
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}


int V;
vector<Station> stations;
vector<bool> visited;

void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1;
  dfs(stations[u].dest.first.first);
  dfs(stations[u].dest.second.first);
}


void SOLVE() {

  while (cin >> V, V != 0) {
  
  if (V == 1) {
    cout << "All stations are reachable.\n";
    return;
  }
  
  stations.assign(V, Station());
  visited.assign(V, 0);
  
  for (int i = 0; i < V; ++i) {
    cin >> stations[i].x >> stations[i].y;
  }

  for (int i = 0; i < V; ++i) {
    
    pair<ii, ii> & dest = stations[i].dest; //{{stationA, dist}, {stationB, dist}}
    int x = stations[i].x, y = stations[i].y;

    for (int q = 0; q < 2; ++q) {
      for (int j = 0; j < V; ++j) {
        if (i == j) continue;
      
        int &k1 = dest.first.first, &k2 = dest.second.first;
        if (j == k1 || j == k2) continue;
        
        int d = distsq(stations[i], stations[j]);
      
        int x1 = stations[k1].x, y1 = stations[k1].y, x2 = stations[k2].x, y2 = stations[k2].y;
        int &d1 = dest.first.second, &d2 = dest.second.second;

        if (d1 == 2e9) {
          d1 = d; k1 = j;
        } else if (d2 == 2e9) {
          d2 = d; k2 = j;
        } else if (d<d1 || (d==d1 && (x<x1 || (x==x1 && y<y1)))) {
          d1 = d; k1 = j;
        } else if (d<d2 || (d==d2 && (x<x2 || (x==x2 && y<y2)))) {
          d2 = d; k2 = j;
        }
        
    
      }
    }
//    cout << "Station " << i << " (" << x << ", " << y << "):\n k=" << dest.first.first << " distsq=" << dest.first.second << "\n k=" << dest.second.first << " distsq=" << dest.second.second << "\n";
    
    
  }
  
  dfs(0);
  bool every = 1;
  for (int i = 0; i < V; ++i) {
    if (!visited[i]) {
      every = 0;
      break;
    }
  }
  
  if (every) cout << "All stations are reachable.\n";
  else cout << "There are stations that are unreachable.\n";

  
  
  
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














