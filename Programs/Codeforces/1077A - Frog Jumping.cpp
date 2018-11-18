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
  int t;
  cin >> t;
  while (t--) {
    ll a, b, k;
    cin >> a >> b >> k;
    ll x;
    if (k%2 == 0) {
      x = a*(k/2) - b*(k/2);
    } else {
      x = a*(k/2) - b*(k/2) + a;
    }
    cout << x << endl;
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
