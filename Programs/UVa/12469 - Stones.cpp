#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
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




// state: num. stones remaining, max stones curr. player can take
int dp[1001][1001]; // can we win from this state?

int f(int n, int m) {
  if (n == 0) return 0; // lost
  if (n == 1) return 1; // woon
  if (dp[n][m] != -1) return dp[n][m];

  int ans = 0;
  for (int k = 1; k <= min(n, m) && ans == 0; ++k) {
    if (f(n-k, 2*k) == 0) { // Can the next player win from the next state?
      ans = 1; // if not, we are guaranteed to win from this state!
    }
  }
  return dp[n][m] = ans;
}

void MAIN() {
  memset(dp, -1, sizeof(dp));
  int n;
  while (cin >> n, n != 0) {
    cout << (f(n, n-1) == 1 ? "Alicia\n" : "Roberto\n");
  }
}




int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  MAIN();
}













