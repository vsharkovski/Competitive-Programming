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







void MAIN() {
  ll dp[42]; // dp[n] = number of ways to fit cakes into a 2 by n sized box
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 5;
  for (int n = 3; n <= 40; ++n) {
    //      O           LL          LLJ
    //      O           LO x 4      LJJ x 2
    dp[n] = 1*dp[n-1] + 4*dp[n-2] + 2*dp[n-3];
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << dp[n] << endl;
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













