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


class SkiDay
{
  public:
    int getNumberOfYoungSkiers(int N, int M)
    {
    	int lo = 0, hi = N, mid;
    	while (lo <= hi) {
        mid = (lo + hi) / 2;
        int m1 = 1150*(N-mid) + 900*mid - N*150;
        if (m1 == M) {
          return mid;
        } else if (m1 < M) {
          hi = mid-1;
        } else {
          lo = mid+1;
        }
    	}
    }
};
//
//#ifdef _DEBUG
////#include <iostream>
//int main() {
//
//}
//#endif
