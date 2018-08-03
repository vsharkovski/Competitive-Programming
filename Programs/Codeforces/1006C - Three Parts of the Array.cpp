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
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const int G_V = 1, G_U = -1; //graph visited constant, graph unvisited constant






void SOLVE() {

  int n;
  cin >> n;
  
  vi q(n);
  vector<ll> dp(n);
  
  cin >> q[0];
  dp[0] = q[0];
  
  for (int i = 1; i < n; ++i) {
    cin >> q[i];
    dp[i] = dp[i-1] + q[i];
  }
  
  ll maxsa = 0;
  
  for (int i = 0; i < n; ++i) {
    ll sa = dp[i];
    ll sc = dp[n-1] - dp[i];
    
    // sa (i=left) sb (mid) sc (right)
    int left = i, right = n-1, mid;
    while (sa != sc && left <= right) {
      mid = (left+right)/2;
      sc = dp[n-1] - dp[mid];
      if (sc == sa) break;
      else if (sa < sc) {
        left = mid+1;
      } else {
        right = mid-1;
      }
    }
    
    if (sa == sc) {
      maxsa = max(sa, maxsa);
    }
  }
  
  cout << maxsa << endl;
  


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




