#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;

typedef long double ld;


bool isbigger(ld a, ld b) {
  return a-b > EPS;
}
bool issmaller(ld a, ld b) {
  return b-a > EPS;
}


void solve() {

  string inp;
  while (cin >> inp, inp != "END") {

    ld x = stold(inp);
    ld a = 0.0, d = 1.0;
    ld t = (d-a)/3.0;
    ld b = a+t, c = b+t;

    int i;
    for (i = 0; i < 10; ++i) {
      if (issmaller(b, x) && issmaller(x, c)) { //check if x is in interval ( a+(d-a)*(1/3), a+2*(d-a)*(1/3) )
        cout << "NON-MEMBER\n";
        break;
      } else if (issmaller(x, b)) {
        d = b;
      } else {
        a = c;
      }
      t = (d-a)/3.0;
      b = a + t;
      c = b + t;
    }

    if (i == 10) {
      cout << "MEMBER\n";
//      cout << setprecision(10) << fixed << "a=" << a << " b=" << b << " c=" << c << " d=" << d << " x=" << x << endl;
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
  solve();
}
