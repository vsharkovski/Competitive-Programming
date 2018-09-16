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
  
  int n;
  bool a[102];

  int num1 = 0;
  
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i]) num1++;
  }
  
  int ans = -2e9;
  
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int cnt = 0;
      for (int k = i; k <= j; ++k) {
        if (a[k]) --cnt;
        else ++cnt;
      }
      ans = max(ans, cnt);
    }
  }
  
  cout << ans+num1 << endl;

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



















