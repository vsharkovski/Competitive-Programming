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

  int n, a[10];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int mask = 1; mask < (1 << n); ++mask) {
    int na = 0, nb = 0, ta = 0, tb = 0;
    for (int j = 0; j < n; ++j) {
      if (mask & (1 << j)) {
        ta += a[j];
        ++na;
      } else {
        tb += a[j];
        ++nb;
      }
    }
    if (ta != tb && ta > 0 && tb > 0) {
      cout << na << endl;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          cout << j+1 << " ";
        }
      }
      return;
    }
  }
  cout << -1;

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







