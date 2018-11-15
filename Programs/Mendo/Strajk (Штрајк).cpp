#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





void Solve() {

  int n;
  cin >> n;

  int sedm = n / 5;
  int den = n % 5;

  while (n > 0) {
    if (sedm < 18) {
      if (den == 5) {
        --n;
      }
      if (den == 6) {
        ++sedm;
        den = 0;
      } else {
        ++den;
      }
    } else {
      if (den < 6) {
        --n;
        ++den;
      } else {
        ++sedm;
        den = 0;
      }
    }
  }

  cout << max(0, sedm - 17) << endl;

}



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
