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

//#include <iostream>

class Squares {
public:
  const int OFS = 20;
  int findMax(vi xc, vi yc) {
    int ans = 0;
    int c[82][82] = {};
    for (int i = 0; i < xc.size(); ++i)
      ++c[OFS+xc[i]][OFS+yc[i]];
    for (int x = 0; x <= 20; ++x) {
      for (int y = 0; y <= 20; ++y) {
        for (int a = 1; a <= 20; ++a) {
          for (int b = 0; b <= 20; ++b) {
            int c1 = c[OFS+x][OFS+y];
            int c2 = c[OFS+x+a][OFS+y+b];
            int c3 = c[OFS+x+b][OFS+y-a];
            int c4 = c[OFS+x+a+b][OFS+y-a+b];
            if (min(c1, min(c2, min(c3, c4))) > 0) {
              ans += c1*c2*c3*c4;
            }
          }
        }
      }
    }
    return ans;
  }
};

//#ifdef _DEBUG
//int main() {
//  Squares g;
//  cout << g.findMax({5,7,4,2,5,5,1,1,0}, {1,5,6,2,2,2,1,1,5}) << endl;
//}
//#endif
