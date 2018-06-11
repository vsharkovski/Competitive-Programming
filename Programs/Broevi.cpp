#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int z, r;
    cin >> z >> r;
    int a = (z+r)/2, b = z-a;
    if ((z % 2) != (r % 2) || a < 0 || b < 0 || a+b != z || a-b != r || a < b) {
        cout << "NE MOZE\n";
        return 0;
    }
    cout << a << " " << b << '\n';

}
