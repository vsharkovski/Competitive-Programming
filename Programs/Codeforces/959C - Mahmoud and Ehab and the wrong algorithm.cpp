#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const double EPS = 1e-9;
const ll mod = 1e9 + 7;






void Solve() {

  int n;
  cin >> n;

  if (n <= 5) {
    cout << "-1\n";
  } else {
    cout << "1 2\n1 3\n1 4\n";
    for (int u = 5; u <= n; ++u) {
      cout << 2 << " " << u << "\n";
    }
  }

  for (int u = 2; u <= n; ++u) {
    cout << "1 " << u << "\n";
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
