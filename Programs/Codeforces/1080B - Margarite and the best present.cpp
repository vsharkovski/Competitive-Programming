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
  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll p1 = l % 2 == 0 ? l : l+1;
    ll p2 = r % 2 == 0 ? r : r-1;
    ll sum1 = 0;
    if (p1 < p2) {
      ll n = (p2 - p1) / 2 + 1;
      sum1 = n*(p1 - 1) + n*n;
    } else if (p1 == p2) {
      sum1 = p1;
    }
    ll o1 = l % 2 == 0 ? l+1 : l;
    ll o2 = r % 2 == 0 ? r-1 : r;
    ll sum2 = 0;
    if (o1 < o2) {
      ll n = (o2 - o1) / 2 + 1;
      sum2 = n*(o1 - 1) + n*n;
    } else if (o1 == o2) {
      sum2 = o1;
    }
    cout << sum1 - sum2 << endl;
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
