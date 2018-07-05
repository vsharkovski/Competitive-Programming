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


///credit to book 'competitive programming 3'


int coins[5] = {50, 25, 10, 5, 1};

int dp[6][7500];
int ways(int type, int value) {
  //one way, use nothing
  if (value == 0) return 1;
  //can't reach negative value or we've considered all types
  if (value < 0 || type == 5) return 0;
  //dp
  if (dp[type][value] != -1) return dp[type][value];
  // consider not taking and taking
  return dp[type][value] =
    ways(type+1, value) + ways(type, value - coins[type]);
}


void SOLVE() {

  int v; //max < 7500

  while (cin >> v) {
    memset(dp, -1, sizeof(dp));
    cout << ways(0, v) << endl;
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
















