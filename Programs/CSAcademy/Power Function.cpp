   #include <bits/stdc++.h>
using namespace std;

double power(double X, int Y) {
    bool negative = false;
    if (Y < 0) {
        negative = true;
        Y = -Y;
    }
    double res = 1;
    while (Y) {
        if (Y & 1) res *= X;
        X *= X;
        Y /= 2;
    }
    if (negative) res = 1 / res;
    return res;
}
   
int main() {
    double X, Y;
    cin >> X >> Y;
    cout << setprecision(6) << fixed << power(X, Y);
    return 0;
}
