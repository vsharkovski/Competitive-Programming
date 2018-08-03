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

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;


void SOLVE() {

  unordered_map<int, int> getpower;
  for (int i = 0; i < 32; ++i) {
    getpower[1<<i] = i;
  }

  int n, q;
  cin >> n >> q;

  vector<int> a(32, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[getpower[x]];
  }

  while (q--) {

    ll x;
    cin >> x;

    int steps = 0;

    for (int d = 31; x > 0 && d >= 0; --d) {
      ll dvojce = 1 << d;
      if (dvojce > x || a[d] == 0) continue;

      ll lo = 0, hi = a[d], mid, ans = -1;
      while (lo <= hi) {
        mid = (lo+hi) / 2;
        if (mid*dvojce == x) {
          ans = mid;
          break;
        } else if (mid*dvojce > x) {
          hi = mid-1;
        } else {
          lo = mid+1;
          ans = mid;
        }
      }
//      cout << "2^" << d << "=" << dvojce << " ans=" << ans << " " << x << "-" << ans*dvojce << "=";
      x -= ans*dvojce;
//      cout << x << endl;
      steps += ans;

    }

    if (x != 0) steps = -1;
    cout << steps << endl;

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
