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


vector<int> coins;
int n;

ll dp[25][10005];

ll ways(int i, int m) {
  if (i == n || m < 0) return 0;
  if (m == 0) return 1;
  if (dp[i][m] != -1) return dp[i][m];
  return dp[i][m] = ways(i+1, m) + ways(i, m - coins[i]); 
}


void SOLVE() {

  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= 21; ++i) {
    coins.push_back(i*i*i);
  }
  n = coins.size();
  
  int m;
  while (cin >> m) {
    cout << ways(0, m) << endl;
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



















