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






int n;
double m;
double a[1001], b[1001];

inline bool check(double fuel) {
  for (int i = 0; i < n; ++i) {
    double burnt = (m + fuel) / b[i];
    if (burnt > fuel) return false;
    fuel -= burnt;
    burnt = (m + fuel) / a[i];
    if (burnt > fuel) return false;
    fuel -= burnt;
  }
  return true;
}

void MAIN() {

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  double lo = 1.0, hi = 1000000001.0, mid;
  double ans = -1;

  while (abs(hi - lo) > EPS) {
    mid = (lo + hi) / 2.0;
    if (check(mid)) {
      ans = mid;
      hi = mid;
    } else {
      lo = mid;
    }
  }

  cout << setprecision(8) << fixed << ans << endl;






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













