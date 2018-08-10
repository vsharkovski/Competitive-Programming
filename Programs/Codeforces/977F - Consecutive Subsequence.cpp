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

  int n;
  cin >> n;

  map<int, int> dp;
  int posl, maxlen = 0;

  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int &curr = dp[a[i]], t = dp[a[i]-1] + 1;
    if (t > curr) {
      curr = t;
      if (t > maxlen) {
        maxlen = t;
        posl = a[i];
      }
    }
  }

  cout << maxlen << endl;
  vi ans(maxlen);
  for (int i = n-1, k = maxlen-1; i >= 0 && k >= 0; --i) {
    if (a[i] == posl) {
      ans[k--] = i+1;
      --posl;
    }
  }

  for (int i = 0; i < maxlen; ++i) {
    cout << ans[i] << ' ';
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








