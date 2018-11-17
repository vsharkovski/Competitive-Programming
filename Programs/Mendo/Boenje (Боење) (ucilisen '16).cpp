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
  ll R, C;
  cin >> R >> C;
 
  ll c0 = (C / 3) + (C % 3 > 0);
  ll c1 = (C / 3) + (C % 3 > 1);
  ll c2 = (C / 3);
 
  ll r0 = (R / 3) + (R % 3 > 0);
  ll r1 = (R / 3) + (R % 3 > 1);
  ll r2 = (R / 3);
 
  ll r = r0 * c0 + r1 * c2 + r2 * c1;
  ll y = r0 * c1 + r1 * c0 + r2 * c2;
  ll g = r0 * c2 + r1 * c1 + r2 * c0;
 
  cout << r << " " << y << " " << g << "\n";
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
