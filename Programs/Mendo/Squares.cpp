#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

void Solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int d = 1; d * d <= n; ++d) {
    if (n % d != 0) continue;
    for (int x = 1; x <= (n/d + 1)/2; ++x) {
      if (gcd(x, n/d + 1) == 1) {
        ++ans;
      }
    }
    if (d * d == n) continue;
    for (int x = 1; x <= (d + 1)/2; ++x) {
      if (gcd(x, d + 1) == 1) {
        ++ans;
      }
    }
  }
  cout << ans << endl;
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
