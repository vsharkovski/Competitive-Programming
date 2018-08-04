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





void SOLVE() {

  int n, m;
  cin >> n >> m;
  bool line[m+5] = {};
  while (n--) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) line[i] = 1;
  }
  vi ans;
  for (int i = 1; i <= m; ++i) {
    if (line[i] == 0) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int x : ans) cout << x << ' ';


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






