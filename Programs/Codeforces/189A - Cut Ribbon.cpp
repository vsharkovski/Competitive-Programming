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


int n, a, b, c;

void SOLVE() {

  cin >> n >> a >> b >> c;
  
  int maxcnt = 0;
  
  for (int x = 0; x <= n; x += a) {
    for (int y = 0; y <= n-x; y += b) {
      int z = n-x-y;
      if (z % c == 0) {
//        cout << x/a << "*" << a << " + " << y/b << "*" << b << " + " << z/c << "*" << c << " = " << n << endl;
        maxcnt = max(maxcnt, x/a + y/b + z/c);
      }
    }
  }
  
  cout << maxcnt << endl;
  
  

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



















