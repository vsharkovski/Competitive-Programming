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
  ll n, k;
  cin >> n >> k;
  ll x = (2 * n) / k;
  if (k * x < 2 * n) ++x;
  ll y = (5 * n) / k;
  if (k * y < 5 * n) ++y;
  ll z = (8 * n) / k;
  if (k * z < 8 * n) ++z;
  cout << x + y + z << endl;


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
