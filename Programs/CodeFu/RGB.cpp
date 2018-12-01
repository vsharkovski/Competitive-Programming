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


class RGB {
public:

    int countWays(int N) {
        // (N + K - 1) choose (K - 1)
        // K = 3
        return ll(N + 1) * ll(N + 2) / 2LL;
    }

};

#ifdef _DEBUG
int main() {

}
#endif
