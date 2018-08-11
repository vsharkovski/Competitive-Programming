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









bool taken[20];

void MAIN() {

  ll a, b;
  cin >> a >> b;

  int digits = 0;
  int data[10] = {};
  ll ia = a;
  while (ia != 0) {
    ++data[ia % 10];
    ++digits;
    ia /= 10;
  }

  vi bdigits;
  ll ib = b;
  while (ib != 0) {
    bdigits.push_back(ib % 10);
    ib /= 10;
  }

  if (digits < bdigits.size()) {
    for (int d = 9; d >= 0; --d) {
      while (data[d]--) {
        cout << d;
      }
    }
    return;
  }

  // same num digits
//  cout << "a: " << a << "\nb: " << b << endl;

  a = 0;
  for (int i = digits-1; i >= 0; --i) {
    a *= 10;
    for (int d = 9; d >= (i == digits-1); --d) {
      if (data[d] == 0) continue;

      ll ta = a + d;
      --data[d];
      for (int d1 = 0; d1 <= 9; ++d1) {
        for (int j = 0; j < data[d1]; ++j) {
          ta = 10*ta + d1;
        }
      }
      ++data[d];

//      cout << "i=" << i << " a=" << a << " d=" << d << " ta: " << ta << endl;

      if (ta <= b) {
//        cout << "  success" << endl;
        a += d;
        --data[d];
        break;
      }
    }
  }

  cout << a << endl;







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








