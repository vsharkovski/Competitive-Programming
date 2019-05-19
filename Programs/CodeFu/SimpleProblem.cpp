#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
#include <map>
using namespace std;
//#include <iostream>


const int mod = 1e9 + 7;

void add_self(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

class SimpleProblem
{
  public:
    int minimumNumbers(vector<int> arr, int K)
    {
        map<int, int> sums; // sum, min cnt
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            arr[i] %= mod;
        }
        for (int m = 0; m < (1<<(n/2)); ++m) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n/2; ++i) {
                if (m & (1 << i)) {
                    add_self(sum, arr[i]);
                    ++cnt;
                }
            }
            if (sums.count(sum)) {
                sums[sum] = min(sums[sum], cnt);
            } else {
                sums[sum] = cnt;
            }
        }
        int ans = 1e9;
        for (int m = 0; m < (1<<(n-n/2)); ++m) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n-n/2; ++i) {
                if (m & (1 &lt;< i)) {
                    add_self(sum, arr[n/2 + i]);
                    ++cnt;
                }
            }
            if (sums.count(K-sum)) {
                ans = min(ans, cnt + sums[K-sum]);
            }
            if (sums.count(K-sum+mod)) {
                ans = min(ans, cnt + sums[K-sum+mod]);
            }
        }
        if (ans == 1e9) ans = -1;
        return ans;
    }
};

