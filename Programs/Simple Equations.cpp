#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

/*
It's not a perfect solution
(it gets AC on the judge's input, but it gives bad output for
 Morass's input (see uDebug))
*/


void main1() {

  int N;
  cin >> N;
  while (N--) {

    int A, B, C;
    cin >> A >> B >> C;

    int xr = 1e9, yr = 1e9, zr = 1e9;

    for (int x=1, xx=x*x; xx < C; ++x, xx=x*x) {
      for (int y=1, yy=y*y; yy < C-xx; ++y, yy=y*y) {
        if (x == y) continue;
        double zd = sqrt(C-xx-yy);
        if (zd == floor(zd)) {
          //x^2 + y^2 + z^2 = C
          int z = zd;
          if (z == x || z == y) continue;
          for (int mask = 0; mask < 8; ++mask) {
            int x1 = (mask & 1) ? x : -x;
            int y1 = (mask & 2) ? y : -y;
            int z1 = (mask & 4) ? z : -z;
            if (x1 + y1 + z1 == A && x1*y1*z1 == B) {
              if (x1 > y1) swap(x1, y1);
              if (x1 > z1) swap(x1, z1);
              if (y1 > z1) swap(y1, z1);
              if (x1 < xr || (x1 == xr && (y1 < yr || (y1 == yr && z1 < zr)))) {
                xr = x1; yr = y1; zr = z1;
              }
            }
          }
        }
      }
    }

    if (xr == 1e9)
      cout << "No solution.\n";
    else
      cout << xr << ' ' << yr << ' ' << zr << endl;
  }

}






int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  main1();
}
