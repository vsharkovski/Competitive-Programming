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



int R, buttons[12];
int dist[10002]; //0, ..., 9999

void bfs(int src) {
  queue<int> q;
  q.push(src);
  dist[src] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < R; ++i) {
      int v = (u + buttons[i]) % 10000;
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

void SOLVE() {
  int L, U;
  int CN = 1;
  while (cin >> L >> U >> R, L != 0 || R != 0 || U != 0) {
    for (int i = 0; i < R; ++i) {
      cin >> buttons[i];
    }
    sort(buttons, buttons+R, greater<int>());
    memset(dist, -1, sizeof(dist));
    bfs(L);
    cout << "Case " << CN++ << ": ";
    if (dist[U] == -1) {
      cout << "Permanently Locked\n";
    } else {
      cout << dist[U] << endl;
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













