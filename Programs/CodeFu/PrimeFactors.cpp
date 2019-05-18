#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
using namespace std;
//#include <iostream>

typedef long long ll;

const ll maxnum = 1e7 + 1000;

class PrimeFactors
{
  public:
    ll STRTOLL(string& s) {
        ll res = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            res = 10*res + (s[i]-'0');
        }
        return res;
    }
    string LLTOSTR(ll x) {
        string res = "";
        if (x == 0) {
            res += '0';
        } else {
            while (x > 0) {
                res += char((x % 10)+'0');
                x /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bitset<maxnum> iscomposite;
    string count(string A, string B)
    {
        ll a = STRTOLL(A), b = STRTOLL(B);
        ll ans = 0;
        for (ll p = 2; p < maxnum; ++p) {
            if (iscomposite[p]) continue;
            for (ll q = p*p; q < maxnum; q += p) {
                iscomposite[q] = 1;
            }
            ll q = p*p;
            while (q <= b) {
                if (q >= a) {
                    ++ans;
                }
                ll r = q*p;
                if (r/q != p) break;
                q *= p;
            }
        }
        return LLTOSTR(ans);
    }
};


//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    PrimeFactors a;
//    cout << a.count("3957011678130","84436881240831") << endl;
//}
