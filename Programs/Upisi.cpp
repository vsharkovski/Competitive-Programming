#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int rcm = 1, rcc = 1, rpt;
    {
        int h, m;
        cin >> h >> m;
        rpt = h*60 + m;
    }
    for (int i = 1; i < n; ++i) {
        int h, m;
        cin >> h >> m;
        int t = h*60 + m;
        if (t != rpt) {
            rcc = 1;
            rpt = t;
        }
        else {
            rcc++;
            if (rcc > rcm) rcm = rcc;
        }
    }
    cout << rcm;
}