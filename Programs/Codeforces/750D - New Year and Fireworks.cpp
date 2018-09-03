#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}




// 0, 1,  2, 3,  4, 5,  6, 7
// n, ne, e, se, s, sw, w, nw
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int nxd[8][2] = {{7, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 0}};

int n;
int t[32];
bool dp[302][302][31][8]; // x, y, recursion level, direction
bool visited[302][302];

void napraj(int x, int y, int i, int d) {
  if (i == n || dp[x][y][i][d]) return;
  
  dp[x][y][i][d] = 1;
  for (int ti = 0; ti < t[i]; ++ti) {
    x += dx[d];
    y += dy[d];
    visited[x][y] = 1;
  }
  
  napraj(x, y, i+1, nxd[d][0]);
  napraj(x, y, i+1, nxd[d][1]);
}

void Solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  
  memset(visited, 0, sizeof(visited));
  memset(dp, 0, sizeof(dp));
  napraj(150, 150, 0, 0);

  int cnt = 0;
  for (int i = 0; i <= 301; ++i) {
    for (int j = 0; j <= 301; ++j) {
      if (visited[i][j]) ++cnt;
    }
  }
  
  cout << cnt << endl;
  
//  for (int i = 160; i >= 140; --i) {
//    for (int j = 160; j >= 140; --j) {
//      if (visited[j][i]) cout << 'o'; else cout << '.';
//    }
//    cout << endl;
//  }
  
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}


















