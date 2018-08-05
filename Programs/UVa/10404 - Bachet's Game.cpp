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

  int n, m, toremove[10];
  while (cin >> n >> m) {
    for (int i = 0; i < m; ++i) {
      cin >> toremove[i];
    }

    bool dp[n+2]; // dp[x] = can a player (make an optimal move to) win with x stones remaining?
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; ++i) {
      dp[toremove[i]] = 1; // Stan can win if he can take all the remaining stones in one step
    }

    for (int rem = 1; rem <= n; ++rem) {
      if (dp[rem]) continue; // we already know Stan can win at this step, so just continue
      // imagine it's Stan's turn with rem stones remaining.
      // if Stan can make a move so that Ollie is in a position in which it is impossible to win,
      // (i.e if dp[rem - toremove[i]] == 0 for some i in [0, m-1])
      // then Stan can win from this step (i.e he can make an optimal move)
      for (int i = 0, step = toremove[0]; i < m; step = toremove[++i]) {
        if (step <= rem && dp[rem-step] == 0) {
          dp[rem] = 1;
          break;
        }
      }
    }

    if (dp[n]) {
      cout << "Stan wins\n";
    } else {
      cout << "Ollie wins\n";
    }
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













