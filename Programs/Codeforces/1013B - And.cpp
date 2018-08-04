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

  int n, x;
  cin >> n >> x;

  set<int> s1, s2;

  bool ans[3] = {};

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (s1.count(a)) {
      ans[0] = 1;
    }
    if (s1.count(a&x)) {
      ans[1] = 1;
    }
    if (s2.count(a)) {
      ans[1] = 1;
    }
    if (s2.count(a&x)) {
      ans[2] = 1;
    }
    s1.insert(a);
    s2.insert(a&x);
  }

  if (ans[0]) cout << 0;
  else if (ans[1]) cout << 1;
  else if (ans[2]) cout << 2;
  else cout << -1;

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





