#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;

// works fine on uDebug

double p, q, r, s, t, u;

bool can(double x) {
  return EPS > (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

void solve() {

  cout << setprecision(4) << fixed;

  while (cin >> p) {
    cin >> q >> r >> s >> t >> u;

    if (p*exp(-1) + q*sin(1) + r*cos(1) + s*tan(1) + t + u > EPS || p + r + u < 0) {
      cout << "No solution\n";
      continue;
    }

    long double lo = 0.0, hi = 1.0, mid = 0.0, ans = -1.0;
    while (abs(hi-lo) > EPS) {
      mid = (lo+hi) / 2.0;
      if (can(mid)) {
        ans = mid;
        hi = mid;
      } else {
        lo = mid;
      }
    }

    if (can(ans))
      cout << ans << endl;
    else
      cout << "No solution" << endl;
  }



}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  solve();
}
