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

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;


const int M = 1e6;

ll dp[105][105];

ll ways(int n, int k) {
  if (k == 1) return 1;
  if (dp[n][k] != -1) return dp[n][k];

  ll ans = 0;
  for (int x = 0; x <= n; ++x) {
    ans = (ans + ways(n-x, k-1)) % M;
  }
  return dp[n][k] = ans % M;
}

void SOLVE() {

  int n, k;
  while (cin >> n >> k, n != 0 && k != 0) {
    memset(dp, -1, sizeof(dp));
    cout << ways(n, k) << endl;
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












