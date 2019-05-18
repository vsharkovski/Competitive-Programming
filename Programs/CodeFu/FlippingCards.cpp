#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
using namespace std;
//#include <iostream>

class FlippingCards
{
  public:
    int transform(string cards)
    {
        int n = cards.size();
        vector<bool> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = cards[i] == 'U';
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                if (i+2 >= n) {
                    return -1;
                }
                ++ans;
                a[i] = 0;
                a[i+1] = !a[i+1];
                a[i+2] = !a[i+2];
            }
        }
        return ans;
    }
};

//int main() {
//    FlippingCards a;
//    cout << a.transform("DUDDDDUDUD");
//}
