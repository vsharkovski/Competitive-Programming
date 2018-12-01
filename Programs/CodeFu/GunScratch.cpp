#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;


class GunScratch {
public:
  int matches(vector<string> bullets, string bullet) {
    int len = bullet.length();
    for (int si = 0; si < bullets.size(); ++si) {
      for (int i = 0; i < len; ++i) {
        bool ok = 1;
        for (int j = 0; j < len && ok; ++j) {
          if (bullet[(i+j)%len] != bullets[si][j]) {
            ok = 0;
          }
        }
        if (ok) {
          return si;
        }
      }
    }
    return -1;
  }
};

#ifdef _DEBUG
//#include <iostream>
int main() {
  GunScratch g;
//  cout << g.matches({"|| || ||","| | |||"}, "| || |||");
}
#endif
