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
vi reachable, dist; //(V, 2e9)
bool first;


void bfs(int s, int X) {
  vi *d = first ? &reachable : &dist;
  d->at(s) = 0;
  
  queue<int> q;
  q.push(s);
  
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    
    if (u == X) {
      continue;
    }
    
    for (int i = 0; i < adjlist[u].size(); ++i) {
      int v = adjlist[u][i];
      if (d->at(v) == 2e9) {
        d->at(v) = d->at(u) + 1; //one more layer, though not needed in this problem
        q.push(v);
      }
    }
  }
}


void SOLVE() {
  int T;
  cin >> T;
  for (int CN = 1; CN <= T; ++CN) {

    cin >> V;
    adjlist.assign(V, vi());
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        bool e;
        cin >> e;
        if (e) adjlist[i].push_back(j);
      }
    }
    
    first = 1;
    reachable.assign(V, 2e9);
    bfs(0, V); //find reachable points
    first = 0;
    
    //I hate stupid output formats!
    cout << "Case " << CN << ":";
    cout << "\n+";
    for (int i = 0; i < V+V-1; ++i) cout << "-";
    cout << "+\n";
    
    for (int X = 0; X < V; ++X) {
      dist.assign(V, 2e9);
      bfs(0, X);
      
      cout << "|";
      for (int Y = 0; Y < V; ++Y) {
        if (reachable[Y] != 2e9 && (X == Y || dist[Y] == 2e9)) {
          cout << "Y|";
        } else {
          cout << "N|";
        }
      }
      cout << "\n+";
      for (int i = 0; i < V+V-1; ++i) cout << "-";
      cout << "+\n";
      
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















