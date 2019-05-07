#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
//#include <iostream>

typedef long long ll;
typedef pair<ll, ll> pll;



const ll mod = 1e9 + 7;
static pll dp[105][1005][2];

class SecretNumbers {
public:
    int len, K;
    int N[105];
    ll pow10[105];
    // dp[pos][sum_digits][smaller_than_N] = (number of numbers, sum of numbers)
    void combine(int pos, int c, pll& res, pll& res2) {
        res.first += res2.first;
        res.first %= mod;
        res.second += res2.second;
        res.second %= mod;
        res.second += ((res2.first*pow10[len-pos-1])%mod)*c;
        res.second %= mod;
    }
    pll dfs(int pos, int sumd, int smaller) {
        auto& res = dp[pos][sumd][smaller];
        if (res.first != -1) {
            return res;
        }
        res.first = res.second = 0;
        if (pos == len) {
            if (sumd == K) {
                res.first = 1;
            }
        } else {
            if (smaller) {
                for (int c = 0; c <= 9; ++c) {
                    if (sumd + c <= K) {
                        auto res2 = dfs(pos+1, sumd+c, 1);
                        combine(pos, c, res, res2);
                    }
                }
            } else {
                for (int c = 0; c < N[pos]; ++c) {
                    if (sumd + c <= K) {
                        auto res2 = dfs(pos+1, sumd+c, 1);
                        combine(pos, c, res, res2);
                    }
                }
                if (sumd + N[pos] <= K) {
                    auto res2 = dfs(pos+1, sumd+N[pos], 0);
                    combine(pos, N[pos], res, res2);
                }
            }
        }
        return res;
    }
    int findSum(string _N, int _K) {
        len = _N.length();
        for (int i = 0; i < len; ++i) {
            N[i] = _N[i] - '0';
        }
        K = _K;
        for (int pos = 0; pos <= 100; ++pos) {
            for (int sumd = 0; sumd <= 1000; ++sumd) {
                for (int smaller = 0; smaller <= 1; ++smaller) {
                    dp[pos][sumd][smaller].first = -1;;
                }
            }
        }
        pow10[0] = 1;
        for (int i = 1; i <= len; ++i) {
            pow10[i] = (pow10[i-1] * 10) % mod;
        }
        auto ans = dfs(0, 0, 0);
        return ans.second;
    }
};
//
//int main() {
//    SecretNumbers nut;
//    cout << nut.findSum("40178114685284207017", 60) << endl;
//}
