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





int VISITED = 0, UNVISITED = -1;



unordered_map<string, int> nametonum;

int numitems;

vector<vi> adjlist;
int cost[65][65]; // cost[a][b].first * a = cost[b][a] * b


vi dfs_num, dfs_parent;
int a, b;
int P, Q;

void dfs(int u) {
  dfs_num[u] = VISITED;
      
  if (u == b) {
    P = Q = 1;

    while (dfs_parent[u] != -1) {
    
      P *= cost[u][dfs_parent[u]];      // v*p = parent*q
      Q *= cost[dfs_parent[u]][u];

      int gcd = __gcd(P, Q);
      P /= gcd;
      Q /= gcd;

      u = dfs_parent[u];
    }
  
    return;
  }
  
  for (int v : adjlist[u]) {
    if (dfs_num[v] != UNVISITED) continue;
    dfs_parent[v] = u;
    dfs(v);  
  }
}


string itema, itemb;
int m, n;
  
void assertion() {
  if (nametonum.count(itema) == 0) {
    nametonum[itema] = numitems;
    ++numitems;
  }
  if (nametonum.count(itemb) == 0) {
    nametonum[itemb] = numitems;
    ++numitems;
  }
  a = nametonum[itema], b = nametonum[itemb];
  int gcd = __gcd(m, n);
  m /= gcd;
  n /= gcd;

  adjlist[a].push_back(b);
  adjlist[b].push_back(a);
  
  cost[a][b] = m;
  cost[b][a] = n; 
}

void query() {
  if (nametonum.count(itema) == 0 || nametonum.count(itemb) == 0) {
    cout << "? " << itema << " = ? " << itemb << endl;
    return;
  }
  
  a = nametonum[itema], b = nametonum[itemb];
  P = Q = -1;
  
  dfs_num.assign(62, UNVISITED);
  dfs_parent.assign(62, -1);
  dfs(a);
  
  if (P == -1 && Q == -1) {
    cout << "? " << itema << " = ? " << itemb << endl;
  } else {
    cout << Q << " " << itema << " = " << P << " " << itemb << endl;
  }
}

void SOLVE() {
  adjlist.assign(62, vi());
  numitems = 0;
  
  char command, EQ;
  while (cin >> command, command != '.') {
    if (command == '!') {
      cin >> m >> itema >> EQ >> n >> itemb;
      assertion();
    } else {
      cin >> itema >> EQ >> itemb;
      query();
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














