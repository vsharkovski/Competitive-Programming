#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
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

// Credit to the book 'Competitive Programming 3'
// DP (bottom up)


void SOLVE() {

  int T;
  cin >> T;
  while (T--) {

    int m, c;
    int price[25][25]; //g, model
    cin >> m >> c;

    bool reachable[25][205]; //g, money
    memset(reachable, 0, sizeof(reachable));

    for (int i = 0; i < c; ++i) {
      int k;
      cin >> k;
      price[i][0] = k;
      for (int j = 1; j <= k; ++j) {
        cin >> price[i][j];
      }
    }

    //initial states
    for (int pi = 1; pi <= price[0][0]; ++pi) {
      int money1 = m - price[0][pi];
      if (money1 >= 0) { //prevent out of bounds errors
        reachable[0][money1] = 1;
      }
    }
    //for each remaining garment
    for (int g = 1; g < c; ++g) {
      for (int money = 0; money <= m; ++money) {
        if (reachable[g-1][money] == 0) continue;
        for (int pi = 1; pi <= price[g][0]; ++pi) {
          int money1 = money - price[g][pi];
          if (money1 >= 0) {
            reachable[g][money1] = 1;
          }
        }
      }
    }

    int ans = -1;
    for (int money = 0; money <= m; ++money) {
      if (reachable[c-1][money]) {
        ans = money;
        break;
      }
    }

    if (ans == -1) cout << "no solution\n";
    else cout << m - ans << endl;


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
















