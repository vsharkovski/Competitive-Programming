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


int n, m;
int seq[10010];

int dp[10010][105];

int f(int i, int sum) {
  if (i == n) return sum == 0; //moment of truth
  
  int& ref = dp[i][sum];
  if (ref != -1) return ref;
  
  return ref = (f(i+1, (sum+seq[i]) % m) || f(i+1, (sum-seq[i]) % m));
}


void SOLVE() {
  int T;
  cin >> T;
  
  
  while (T--) {
    cin >> n >> m;
    
    cin >> seq[0]; //only one can't take abs value of
    seq[0] = seq[0] % m;
    
    for (int i = 1; i < n; ++i) {
      cin >> seq[i];
      seq[i] = abs(seq[i]) % m;
    }
    
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 0);
    
    if (ans) cout << "Divisible\n"; else cout << "Not divisible\n";
    
    
  
  
  
  
  
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



















