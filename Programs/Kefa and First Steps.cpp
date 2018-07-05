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


int n;
int a[100005];
int dp[100005];


void SOLVE() {

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0] = 1;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i-1] <= a[i]) {
      dp[i] = 1 + dp[i-1];
      ans = max(ans, dp[i]);
    } else {
      dp[i] = 1;
    }
  }
  cout << ans << endl;




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












