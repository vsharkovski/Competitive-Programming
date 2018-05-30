#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    double x, y;
    cin >> x >> y;

    // x^y vs y^x;
    // log(x^y) vs log(y^x)
    // y log x  vs  x log y
    double log10x = log10(x);
    double log10y = log10(y);
    double a = log10x * y;
    double b = log10y * x;
    if (a < b) cout<<'<'; else if (a>b) cout<<'>'; else cout << '=';
}
