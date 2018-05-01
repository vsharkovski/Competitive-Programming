#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    double hh, mm, h, d, c, n;
    cin >> hh >> mm >> h >> d >> c >> n;

    double t = hh*60+mm;
    double t1 = 20*60;
    double h1 = h + d*max(t1-t, 0.0);
    double c1 = 0.8*c;

    cout << fixed << setprecision(3) << min(c*ceil(h/n), c1*ceil(h1/n));
}
