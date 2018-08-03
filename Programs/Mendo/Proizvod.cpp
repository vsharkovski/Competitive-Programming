#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    double c0, c1;
    cin >> c0 >> c1;
    int a0 = round(c0*100), a1 = round(c1*100);
    int g = __gcd(a0, a1);
    cout << "KUPI " << a1/g << " DOBIJ " << (a0-a1)/g << " GRATIS" << '\n';

}
