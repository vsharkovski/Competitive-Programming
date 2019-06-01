#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <sstream>
using namespace std;

//#include <iostream>

typedef pair<int, int> pii;
typedef long long ll;


class Carambole {
  public:
    string finalPosition(ll dx, ll dy, ll t)
    {
        ll A = 3000, B = 1500;
        ll n = (dx*t)/A;
        ll m = (dy*t)/B;
        ll x = (dx*t)%A;
        ll y = (dy*t)%B;
        if (n % 2 == 1) {
            x = A - x;
        }
        if (m % 2 == 1) {
            y = B - y;
        }
        stringstream ss;
        ss << x << ',' << y;
        return ss.str();
    }
};


//
//int main() {
//    Carambole a;
//    cout << a.finalPosition(58, 30, 73) << '\n';
//}
