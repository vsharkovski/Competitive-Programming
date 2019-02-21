#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;




class OrderedDigits
{
  public:
  int n;
  int digs[302];
  int dp[302][12];
  int dfs(int i, int p) {
    int& res = dp[i][p];
    if (res != -1) {
      return res;
    }
    if (i == n) return res = 0;
    res = 1e9;
    for (int x = p; x <= 9; ++x) {
      int dist = min(abs(digs[i] - x), abs(digs[i] - 10 - x));
      dist = min(dist, abs(digs[i] + 10 - x));
      res = min(res, dist + dfs(i+1, x));
    }
    return res;
  }
  int operations(string number)
  {
    n = number.length();
    for (int i = 0; i < n; ++i) {
      digs[i] = number[i] - '0';
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, 0);
    return ans;
  }
};

