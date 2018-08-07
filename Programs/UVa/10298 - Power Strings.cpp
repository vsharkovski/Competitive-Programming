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





inline bool check(string &s, int len) {
  for (int i = len; i < (int)s.length(); ++i) {
    if (s[i] != s[i-len]) return false;
  }
  return true;
}

void MAIN() {
  string s;
  while (cin >> s, s != ".") {

    int strlen = s.length();
    int ans = 1;

    for (int x = 1; x*x <= strlen; ++x) {
      if (strlen % x) continue;
      int y = strlen / x;
      if (check(s, x)) {
        ans = max(ans, y);
      } else if (check(s, y)) {
        ans = max(ans, x);
      }
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
  MAIN();
}













