#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





int N, M;
int grid[100][15];
int total[15];

int dp[100][1<<15];

/// top down
//int F(int i, int m) {
//  if (m == (1 << M) - 1) return 0;
//  if (i == N) return 1e6;
//  if (dp[i][m] != -1) return dp[i][m];
//  int res = F(i+1, m);
//  for (int j = 0; j < M; ++j) {
//    if (!(m & (1 << j))) {
//      res = min(res, total[j] - grid[i][j] + F(i+1, m | (1 << j)));
//    }
//  }
//  return dp[i][m] = res;
//}

void Solve() {
  cin >> N >> M;
  memset(total, 0, sizeof(total));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> grid[i][j];
      total[j] += grid[i][j];
    }
  }
//  memset(dp, -1, sizeof(dp));
//  cout << F(0, 0) << endl;

  /// bottom up
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < (1 << M); ++j) {
      dp[i][j] = 1e6;
    }
  }
  dp[0][0] = 0;
  for (int j = 0; j < M; ++j) {
    dp[0][1 << j] = total[j] - grid[0][j];
  }
  for (int i = 1; i < N; ++i) {
    for (int m = 0; m < (1 << M); ++m) {
      dp[i][m] = min(dp[i][m], dp[i-1][m]);
      for (int j = 0; j < M; ++j) {
        if (m & (1 << j)) {
          dp[i][m] = min(dp[i][m], total[j] - grid[i][j] + dp[i-1][m & ~(1 << j)]);
        }
      }
    }
  }
  cout << dp[N-1][(1 << M)-1] << endl;
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
