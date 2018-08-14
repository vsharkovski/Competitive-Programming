#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}







void Solve() {

  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n+2, vector<char>(m+2, '.')),
                       grid2(n+2, vector<char>(m+2, '.'));

  vector<vector<int>> dp[4]; //n, s, w, e;
  for (int k = 0; k < 4; ++k)
    dp[k].assign(n+2, vector<int>(m+2, 0));

  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= m; ++c) {
      cin >> grid[r][c];
      if (grid[r][c] == '.') {
        dp[0][r][c] = dp[1][r][c] = dp[2][r][c] = dp[3][r][c] = 0;
      } else {
        dp[0][r][c] = 1 + dp[0][r-1][c];
        dp[1][r][c] = 1 + dp[1][r][c-1];
      }
    }
  }
  for (int r = n; r > 0; --r) {
    for (int c = m; c > 0; --c) {
      if (grid[r][c] == '*') {
        dp[2][r][c] = 1 + dp[2][r+1][c];
        dp[3][r][c] = 1 + dp[3][r][c+1];
      }
    }
  }

  vector<tuple<int,int,int>> stars;
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= m; ++c) {
      if (grid[r][c] == '*') {
        int sz = 1e9;
        for (int k = 0; k < 4; ++k) sz = min(sz, dp[k][r][c]);
        if (sz >= 2) { //sz=2 -> 1
          stars.push_back(make_tuple(r, c, sz-1));
          grid2[r][c] = '*';
          for (int d = 1; d < sz; ++d) {
            grid2[r+d][c] = grid2[r-d][c] = grid2[r][c+d] = grid2[r][c-d] = '*';
          }
        }
      }
    }
  }

  bool same = 1;
  for (int r = 1; r <= n && same; ++r) {
    for (int c = 0; c <= m && same; ++c) {
      if (grid[r][c] != grid2[r][c]) same = 0;
    }
  }

  if (!same) cout << -1 << endl;
  else {
    cout << stars.size() << endl;
    for (auto t : stars) {
      cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }
  }

//  same = 1;
//  cout << "\ngrid:\n";
//  for (int r = 1; r <= n && same; ++r) {
//    for (int c = 1; c <= m && same; ++c) {
//      cout << grid[r][c];
//    }cout << endl;
//  } cout << endl;
//  cout << "grid2:\n";
//  for (int r = 1; r <= n && same; ++r) {
//    for (int c = 1; c <= m && same; ++c) {
//      cout << grid2[r][c];
//    }cout << endl;
//  } cout << endl;

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








