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


int n, k, m;

ll dp[55][55]; //n, k

ll f(int units, int numbars) {
  if (units > n) return 0;
  if (numbars == k) return units == n;
  if (units == n) return 0; //reached n units but numbars < k
  
  ll& ref = dp[units][numbars];
  if (ref != -1) return ref;
  
  ref = 0;
  for (int i = 1; i <= m; ++i) {
    ref += f(units+i, numbars+1);
  }
  return ref;
}

void SOLVE() {

  while (cin >> n >> k >> m) {
   
    memset(dp, -1, sizeof(dp));
    ll total = f(0, 0);
  
    cout << total << endl;

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



















