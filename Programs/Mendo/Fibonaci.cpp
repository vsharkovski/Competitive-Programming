#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int p, k, c = 0, t1 = 0, t2 = 1, nt = 0;
    cin >> p >> k;
    nt = t1 + t2;
    while (nt <= k) {
        if (nt >= p) c++;
        t1 = t2;
        t2 = nt;
        nt = t1 + t2;
    }
    cout << c;
}
