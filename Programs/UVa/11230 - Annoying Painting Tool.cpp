#include <iostream>
#include <iomanip>
#include <algorithm>
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




void SOLVE() {

  int n, m, r, c;
  while (cin >> n >> m >> r >> c, n != 0 && m != 0 && r != 0 && c != 0) {

    bool a[n+2][m+2], b[n+2][m+2] = {};
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        char ch;
        cin >> ch;
        a[i][j] = ch-'0';
      }
    }

    int steps = 0;

    for (int i = 1; i <= n-r+1; ++i) {
      for (int j = 1; j <= m-c+1; ++j) {
        if (a[i][j] != b[i][j]) {
          ++steps;
          for (int k = 0; k < r; ++k) {
            for (int l = 0; l < c; ++l) {
              b[i+k][j+l] = !b[i+k][j+l];
            }
          }
        }
      }
    }

    bool same = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (b[i][j] != a[i][j]) {
          same = 0;
          i = 1e9;
          j = 1e9;
        }
      }
    }

    if (same) {
      cout << steps << endl;
    } else {
      cout << -1 << endl;
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
  SOLVE();
}
