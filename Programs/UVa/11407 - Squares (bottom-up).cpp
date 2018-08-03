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



void SOLVE() {
  
  int coins[105];
  int dp[10005];

  for (int i = 1; i <= 100; ++i) {
    coins[i-1] = i*i;
  }
  
  dp[0] = 0; //base case; it takes 0 squares >= 1 to make 0
  for (int change = 1; change <= 10000; ++change) {
    dp[change] = 2e9;
    for (int i = 0; i < 100 && coins[i] <= change; ++i) {
      dp[change] = min(dp[change], dp[change - coins[i]]);
    }
    ++dp[change];
  }
  
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    cout << dp[N] << endl;
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



