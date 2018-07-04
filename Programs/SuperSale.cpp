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

// Credit to 'Competitive programming 3'


int n;
int W[1002], V[1002];
int dp[1002][32];


int val(int id, int remW) {
  if (remW == 0 || id == n) // no remaining weight or we've considered all items
    return 0;
  if (dp[id][remW] != -1) //already memoized
    return dp[id][remW];
  if (W[id] > remW) //can't take
    return dp[id][remW] = val(id+1, remW);
  //2 choices: ignore or take, choose the one with the higher value
  return dp[id][remW] = max( val(id+1, remW), V[id] + val(id+1, remW - W[id]) );
}

void SOLVE() {

  int T;
  cin >> T;
  while (T--) {

    memset(V, 0, sizeof(V));
    memset(W, 0, sizeof(W));
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> V[i] >> W[i];
    }

    int g, ans = 0;
    cin >> g;
    while (g--) {
      int S;
      cin >> S;
      ans += val(0, S);
    }

    cout << ans << endl;

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
















