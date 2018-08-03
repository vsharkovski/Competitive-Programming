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
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;


void SOLVE() {

  string s;
  cin >> s;
  int n = s.length();
  
  int dp[n] = {};
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i-1] + (s[i-1] == s[i]);
  }

//  for (char ch : s) cout << ch << ' '; cout << endl;
//  for (int i = 0; i < n; ++i) cout << dp[i] << ' '; cout << endl;
  
  
  
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    cout << dp[r-1] - dp[l-1] << endl;  
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








