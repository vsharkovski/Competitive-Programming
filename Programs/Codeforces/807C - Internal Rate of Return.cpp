#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;



void solve() {

  int t;
  vector<double> cf(12);

  cout << setprecision(2) << fixed;

  while (cin >> t, t != 0) {

    for (int i = 0; i <= t; ++i) {
      cin >> cf[i];
    }

    double lo = -0.9999, hi = 10000.0, mid;
    for (int i = 0; i < 100 && abs(hi-lo) > EPS; ++i) {
      mid = (lo + hi) / 2.0;

      double npv = 0.0;
      for (int j = 0; j <= t; ++j) {
        npv += cf[j] / pow(1+mid, j);
      }

      if (npv > EPS) {
        lo = mid;
      } else {
        hi = mid;
      }
    }

    cout << mid << endl;


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
