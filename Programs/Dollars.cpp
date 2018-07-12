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



int n = 11;
int coins[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

ll dp[12][30005];

ll ways(int id, int m) {
  if (id == n || m < 0) return 0;
  if (m == 0) return 1;
  
  if (dp[id][m] != -1) return dp[id][m];
  return dp[id][m] = ways(id+1, m) + ways(id, m - coins[id]);
}

void SOLVE() {

  cout << setprecision(2) << fixed;

  memset(dp, -1, sizeof(dp)); //only need to do this once
  
  string x;
  while (cin >> x, x != "0.00") {
   
    int y = 0;
    for (char ch : x) if (ch != '.') y = 10*y + (ch-'0');
    
    ll ans = ways(0, y);
    
    cout << setw(6) << right << x << setw(17) << right << ans << endl;
  
  
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



















