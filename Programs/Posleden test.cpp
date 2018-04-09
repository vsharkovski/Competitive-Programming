#include <bits/stdc++.h>
using namespace std;
 
int k;
double t1, t2, t3, t4;
 
void calc(int g1, int g2) { // [, )
    int tos = t1+t2+t3+t4;
    int t5min = 5*g1 - tos;
    double pmin = (tos+t5min)/5;
 
    //cout << "t5min:" << t5min << " pmin:" << pmin << endl;
    if (t5min <= 0) {
        cout << 0;
    }
    else if (t5min > 100 || t5min < 0 || pmin < g1 || pmin >= g2) {
        cout << "GRESHKA";
    }
    else {
        cout << t5min;
    }
}
 
int main() {
    cin >> k >> t1 >> t2 >> t3 >> t4;
    if (k == 2) {
        calc(60, 70);
    }
    else if (k == 3) {
        calc(70, 80);
    }
    else if (k == 4) {
        calc(80, 90);
    }
    else if (k == 5) {
        calc(90, 100);
    }
}