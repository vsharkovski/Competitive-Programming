#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int p, v; cin >> p >> v;
    int k = v - p;
    int c = 0;
    int k5a = k / 5, k5b = k % 5;
    c += k5a;
    if (k5b > 0) {
        int k2a = k5b / 2, k2b = k5b % 2;
        c += k2a;
        if (k2b > 0) {
            c += k2b;
        }
    }
    cout << c << endl;
}