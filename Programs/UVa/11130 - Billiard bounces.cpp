#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





void MAIN() {

  // Imagine the ball traveling in a straight line.
  // Whenever it hits a wall, mirror the table from there.

  const double piover180 = acos(-1) / 180.0;

  double X, Y, v0, Adeg, t, x0, y0, d, Arad, dx, dy, x1, y1;
  while(cin >> X >> Y >> v0 >> Adeg >> t, !(X == 0 && Y == 0 && v0 == 0 && Adeg == 0 && t == 0)) {

//    we start at center
    x0 = 0.5 * X;
    y0 = 0.5 * Y;

//    d = v0*t + (a*t^2)/2 ... i
//    v1 = v0 + at = 0 --> a = -v0/t ... ii
//    i, ii --> d = v0*t/2
    d = v0 * t / 2.0;

    Arad = Adeg * piover180;

    dx = d * cos(Arad);
    dy = d * sin(Arad);

    x1 = x0 + dx;
    y1 = y0 + dy;

    cout << floor(x1 / X) << " " << floor(y1 / Y) << endl;
  }


}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  MAIN();
}













