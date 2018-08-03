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




int V;
vector<vi> adjlist;

vi sequence;
vi numchildren;
vi pos;
int dbfsi = 0;

int dbfs(int u) {
  pos[u] = dbfsi;
  sequence[dbfsi] = u;
  ++dbfsi;
  
  for (int v : adjlist[u]) {
    numchildren[u] += 1 + dbfs(v);
  }
  return numchildren[u];
}

void SOLVE() {

  int Q;
  cin >> V >> Q;
  
  adjlist.assign(V, vi());
  
  for (int i = 1; i < V; ++i) {
    int p;
    cin >> p;
    --p;
    adjlist[p].push_back(i); 
  }
  for (vi v : adjlist) {
    sort(all(v));
  }

  sequence.resize(V);
  numchildren.assign(V, 0);
  pos.resize(V);
  
  dbfsi = 0;
  dbfs(0);
  
//  cout << "seq: ";
//  for (int i = 0; i < V; ++i) cout << sequence[i] << ' ';
//  cout << endl;
  
  while (Q--) {
    int u, k;
    cin >> u >> k;
    --u;
    --k;
//    cout << "u=" << u << " k=" << k << " pos[" << u << "]=" << pos[u] << " numchildren[" << u << "]=" << numchildren[u] << endl;
    if (pos[u] + k >= V || k > numchildren[u]) {
      cout << -1 << endl;
      continue;
    }
    cout << sequence[pos[u]+k]+1 << endl;
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


