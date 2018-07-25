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



typedef pair<double, int> pdi;

struct pdiComp {
  bool operator()(pdi &a, pdi &b) {
    return a.first < b.first;
  }
};

inline double eucliddist(int x1, int y1, int x2, int y2) {
  return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

const double INFD = 1000000.0;

int V;
double adjmatrix[505][505];


void SOLVE() {

  cin >> V;
  
  vii systems(V);
  
  for (int i = 0; i < V; ++i) {
    cin >> systems[i].first >> systems[i].second;
  }

  for (int u = 0; u < V; ++u) {
    for (int v = 0; v < V; ++v) {
      if (u == v) continue;
      double d = eucliddist(systems[u].first, systems[u].second, systems[v].first, systems[v].second);
      adjmatrix[u][v] = adjmatrix[v][u] = d > 10.0 ? INFD : d;
    }
  }

  // Dijkstra

  vector<double> dist(V, INFD); // a + b + .. + z
  dist[0] = 0.0;
  
  priority_queue<pdi, vector<pdi>, pdiComp> pq;
  pq.push(pdi(0.0, 0));
  
  while (!pq.empty()) {
    pdi front = pq.top();
    pq.pop();
    double d = front.first;
    int u = front.second;
  
    if (d > dist[u]) continue;
    
    for (int v = 0; v < V; ++v) {
      if (u == v) continue;
      if (dist[u] + adjmatrix[u][v] < dist[v]) {
        dist[v] = dist[u] + adjmatrix[u][v];
        pq.push(pdi(dist[v], v));
      }
    }
  }
  
  cout << setprecision(10) << fixed << dist[V-1] << '\n';

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
