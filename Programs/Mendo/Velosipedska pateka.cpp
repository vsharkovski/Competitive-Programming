#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;






int M, K, N;
int X[102], C[102], R[102];

int dp[102][1002];
bool take[102][1002];

int F(int i, int k) {
  if (k < 0) return -1e7;
  if (i == N || k == 0) return 0;
  if (dp[i][k] != -1) return dp[i][k];
  int o1 = F(i+1, k);
  int o2 = min(M, X[i] + R[i]) - max(0, X[i] - R[i]) + F(i+1, k - C[i]);
  if (o1 >= o2) {
    take[i][k] = 0;
    dp[i][k] = o1;
  } else {
    take[i][k] = 1;
    dp[i][k] = o2;
  }
  return dp[i][k];
}

void Solve() {
  cin >> M >> K >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> C[i] >> R[i];
  }
  memset(dp, -1, sizeof(dp));
  int len = F(0, K);
  int maxunlit = 0;
  int lb = 0;
  for (int i = 0; i < N; ++i) {
    if (take[i][K]) {
      K -= C[i];
      maxunlit = max(maxunlit, max(1, X[i] - R[i]) - lb);
      lb = min(M, X[i] + R[i]);
    }
  }
  maxunlit = max(maxunlit, M - lb);
  cout << len << " " << maxunlit << "\n";

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
