#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <bitset>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

// #include <iostream>



class TotalFibs
{
  public:
    int howMany(int n)
    {
        const int mx = 1000000;
        vector<int> f = {1, 1};
        int a = 1, b = 1, c;
        while (true) {
            c = a + b;
            if (c > mx) break;
            f.push_back(c);
            a = b;
            b = c;
        }
        int ptr = f.size()-1, ans = 0;
        while (n > 0) {
            while (f[ptr] > n) --ptr;
            n -= f[ptr];
            ans += 1;
        }
        return ans;
    }
};


// int main() {
//     TotalFibs a;
//     cout << a.howMany(90) << endl;
// }
