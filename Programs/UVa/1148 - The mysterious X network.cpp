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





int V;
vector<vi> adjlist;

void SOLVE() {
  int T;
  cin >> T;
  while(T--) {

    cin >> V;
    adjlist.assign(V, vi());

    for (int i = 0; i < V; ++i) {
      int u, n, v;
      cin >> u >> n;
      while (n--) {
        cin >> v;
        adjlist[u].push_back(v);
      }
    }

    int src, trg;
    cin >> src >> trg;

    vi dist(V, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == trg) break;
      for (int v : adjlist[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }

    cout << src << " " << trg << " " << dist[trg]-1 << endl;

    if (T>0) cout << endl;
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













