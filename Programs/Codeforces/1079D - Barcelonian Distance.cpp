#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





ld dist(ld x1, ld y1, ld x2, ld y2) {
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

ld calc(ld a, ld b, ld c, ld x1, ld y1, ld x2, ld y2) {
  ld x3, y3, x4, y4;
  x3 = (-c - b*y1) / a;
  x4 = (-c - b*y2) / a;
  y3 = (-c - a*x1) / b;
  y4 = (-c - a*x2) / b;
  ld ans = abs(x1 - x2) + abs(y1 - y2);
  ans = min(ans, dist(x1, y1, x3, y1) + dist(x3, y1, x4, y2) + dist(x4, y2, x2, y2));
  ans = min(ans, dist(x1, y1, x1, y3) + dist(x1, y3, x4, y2) + dist(x4, y2, x2, y2));
  ans = min(ans, dist(x1, y1, x3, y1) + dist(x3, y1, x2, y4) + dist(x2, y4, x2, y2));
  ans = min(ans, dist(x1, y1, x1, y3) + dist(x1, y3, x2, y4) + dist(x2, y4, x2, y2));
  return ans;
}

void Solve() {
  ld a, b, c, x1, y1, x2, y2;
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
  ld ans = min(calc(a, b, c, x1, y1, x2, y2),
               calc(a, b, c, x2, y2, x1, y1));
  cout << setprecision(15) << fixed << ans << endl;

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
