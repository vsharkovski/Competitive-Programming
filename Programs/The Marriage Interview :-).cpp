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

typedef unsigned long long ull;

/*
ull count = 0;
ull trib(int n, int back) {
  ++count;
  ull sum = 0;
  if (n <= 0) return 0;
  if (n == 1) return 1;
  for (int i = 1; i <= back; ++i) {
    sum += trib(n-i, back);
  }
  return sum;
}
*/

ull dp[65][65];

ull trib(int n, int back) {
  if (n <= 1) return 1;
  if (dp[n][back]) return dp[n][back];
  
  ull& ref = dp[n][back];
  ref = 1;

  for (int i = 1; i <= back; ++i) {
    ref += trib(n-i, back);
  }
  return ref;
}


void SOLVE() {

  memset(dp, 0, sizeof(dp));  
    
  int CN = 1;
  int n, back;
  while (cin >> n >> back, n <= 60) {
    cout << "Case " << CN++ << ": " << trib(n, back) << endl;
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



















