#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




ll numwhiteline(ll x1, ll x2) {
  if (x1 % 2 == 0) ++x1;
  if (x2 % 2 == 0) --x2;
  if (x1 > x2) return 0;
  return (x2 - x1) / 2 + 1;
}

ll numblackline(ll x1, ll x2) { //in line
  if (x1 % 2 == 1) ++x1;
  if (x2 % 2 == 1) --x2;
  if (x1 > x2) return 0;
  return (x2 - x1) / 2 + 1;
}

ll numwhite(ll x1, ll y1, ll x2, ll y2) {
  ll t = numwhiteline(y1, y2) * numwhiteline(x1, x2);
  t += numblackline(y1, y2) * numblackline(x1, x2);
  return t;
}

ll numblack(ll x1, ll y1, ll x2, ll y2) {
  ll t = numwhiteline(y1, y2) * numblackline(x1, x2);
  t += numblackline(y1, y2) * numwhiteline(x1, x2);
  return t;
}

void Solve() {
  int T;
  cin >> T;
  while (T--) {

    ll X, Y, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> Y >> X >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ll tw = 0, tb = 0;

    ll nw0 = numwhite(1, 1, X, Y);
    ll nb0 = numblack(1, 1, X, Y);
    ll nw1 = numwhite(x1, y1, x2, y2);
    ll nb1 = numblack(x1, y1, x2, y2);
    ll nw2 = numwhite(x3, y3, x4, y4);
    ll nb2 = numblack(x3, y3, x4, y4);

    ll x5 = max(x1, x3);
    ll y5 = max(y1, y3);
    ll x6 = min(x2, x4);
    ll y6 = min(y2, y4);
    ll nw3 = numwhite(x5, y5, x6, y6);
    ll nb3 = numblack(x5, y5, x6, y6);

    tw = nw0 - nw2 + (nb1 - nb3);
    tb = nb0 - (nb1 - nb3) + nw2;

    cout << tw << " " << tb << endl;
  }

//  cout << numblackline(2, 2) << endl;
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
