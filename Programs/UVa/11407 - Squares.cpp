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

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;


int coins[105];

int dp[10005];

int f(int n) {
  if (n < 0) return 1e8; //inf
  if (n == 0) return 0;
  if (dp[n] != -1) return dp[n];
 
  int mini = 2e9;
  for (int i = 0; i < 100; ++i) {
    mini = min(mini, f(n - coins[i]));
  }
  return dp[n] = 1+mini;
}

void SOLVE() {

  for (int i = 1; i <= 100; ++i) {
    coins[i-1] = i*i;
  }
  memset(dp, -1, sizeof(dp));
  
  int t;
  cin >> t;
  while (t--) {
  
    int N;
    cin >> N;
    cout << f(N) << endl;
  
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
