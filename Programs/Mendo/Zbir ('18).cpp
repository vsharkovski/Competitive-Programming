#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll z;
int c;
 
int main() {
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> z >> c;
    double ones = 1, ones_ = 1;
    for (int i = 0; i < c-1; ++i) {
        ones_ /= 10;
        ones += ones_;
    }
    ll n = z/ones;
    for (int i = 0; i < 100; ++i) {
        ll n1 = n, z1 = 0;
        while (n1 > 0) {
            z1 += n1;
            n1 /= 10;
        }
        if (z1 == z) {
            cout << n << endl;
            break;
        }
        ++n;
    }
}
