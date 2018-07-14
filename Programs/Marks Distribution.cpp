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


int n, t, p;
// 1 <= N <= 70; 1 <= P <= T <= 70;

int dp[75][75]; //

int ways(int subjnum, int currpoints) {
  if (subjnum == n) return currpoints == t;
  
  int& ref = dp[subjnum][currpoints];
  if (ref != -1) return ref;

  ref = 0;
  for (currpoints = currpoints+p; currpoints <= t; ++currpoints) {
    ref += ways(subjnum+1, currpoints);
  }
  return ref;
}

void SOLVE() {
  int k;
  cin >> k;
  while (k--) {
    
    cin >> n >> t >> p;
    memset(dp, -1, sizeof(dp));
    cout << ways(0, 0) << endl;
    
    
    
    
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



















