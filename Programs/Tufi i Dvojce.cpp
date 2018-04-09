#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tm1, ts1, tm2, ts2, dm1, ds1, dm2, ds2;
    cin >> tm1 >> ts1 >> tm2 >> ts2 >> dm1 >> ds1 >> dm2 >> ds2;
    int t = tm1*60+ts1 + tm2*60+ts2;
    int d = dm1*60+ds1 + dm2*60+ds2;
    if (t < d) {
        cout << "T\n";
    }
    else {
        cout << "D\n";
    }
    int rsvk = abs(t-d);
    cout << rsvk/60 << " " << rsvk%60 << endl;
}