#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;






#define EPS 1e-9

void Solve() {
  int t;
  cin >> t;
  cout << setprecision(10) << fixed;
  while (t--) {
    double a1, a2, b1, b2, d;
    cin >> d;
    b1 = (d + sqrt(d*d - 4*d)) / 2.0;
    a1 = b1 != 1 ? b1 / (b1 - 1) : -1;
    b2 = (d - sqrt(d*d - 4*d)) / 2.0;
    a2 = b2 != 1 ? b2 / (b2 - 1) : -1;
    if (a1 >= 0 && b1 >= 0 && abs(a1*b1 - d) < EPS && abs(a1+b1 - d) < EPS) {
      cout << "Y " << a1 << " " << b1 << "\n";
    } else if (a2 >= 0 && b2 >= 0 && abs(a2*b2 - d) < EPS && abs(a2+b2 - d) < EPS) {
      cout << "Y " << a2 << " " << b2 << "\n";
    } else {
      cout << "N\n";
    }
  }
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
