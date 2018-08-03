#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;




void SOLVE() {
  
  int n, m;
  cin >> n >> m;
  
  int c[n], a[m];
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  
  int ans = 0, j = 0;
  for (int i = 0; i < n; ++i) {
    if (j < m && a[j] >= c[i]) {
      ++ans;
      ++j;
    }
  }
  
  cout << ans;




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






