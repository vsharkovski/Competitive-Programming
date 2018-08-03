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

// Works on all input on uDebug, though gets WA on judge
// Feel free to prove that the solution is wrong!
            
        
void SOLVE() {                                

  int n;
  while (cin >> n, n != 0) {
    
    int a[n], dp[n], ans = -1;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    } 
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
      dp[i] = max(0, dp[i-1]+a[i]);
      ans = max(ans, dp[i]);
    }
  
    if (ans <= 0) cout << "Losing streak.\n";     
    else cout << "The maximum winning streak is " << ans << ".\n";

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




                                                 







