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



long long C(int n, int k) {
  static const int MAXN = 60;
  static long long dp[MAXN][MAXN];
  static bool firstCall = true;

  if (firstCall) firstCall = false, memset(dp, -1, sizeof(dp));

  if (n < k) return 0;
  if (k == 0 || n == k) return 1;
  if (dp[n][k] != -1) return dp[n][k];
  return dp[n][k] = C(n-1, k-1) + C(n-1, k);
}

void MAIN() {
  int T;
  cin >> T;
  for (int CT = 1; CT <= T; ++CT) {

    string expr;
    cin >> expr;

    string w1 = "", w2 = "", power = "";
    bool w1done = 0, w2done = 0;

    for (int i = 1; i < expr.length(); ++i) {
      if (!w1done) {
        if (expr[i] == '+') {
          w1done = 1;
        } else {
          w1 += expr[i];
        }
      } else if (!w2done) {
        if (expr[i] == ')') {
          w2done = 1;
          ++i;
        } else {
          w2 += expr[i];
        }
      } else {
        power += expr[i];
      }
    }

    cout << "Case " << CT << ": ";

    int p = stoi(power);
    int p1 = p, p2 = 0;
    while (p1 >= 0) {

      bool hasprev = 0;

      ll c = C(p, p2);
      if (c > 1) {
        if (!hasprev) hasprev = 1;
        else cout << "*";
        cout << c;
      }

      if (p1 >= 1) {
        if (!hasprev) hasprev = 1;
        else cout << "*";
        cout << w1;
        if (p1 > 1) {
          cout << "^" << p1;
        }
      }

      if (p2 >= 1) {
        if (!hasprev) hasprev = 1;
        else cout << "*";
        cout << w2;
        if (p2 > 1) {
          cout << "^" << p2;
        }
      }

      if (p1 > 0) cout << "+";
      --p1, ++p2;
    }

    cout << endl;


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













