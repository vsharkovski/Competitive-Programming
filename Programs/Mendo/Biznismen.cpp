#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string ps, ks;
    cin >> ps >> ks;
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int pi = ps.at(i) - '0';
        int ki = ks.at(i) - '0';
        if (ki < pi) swap(pi, ki);
        cnt += min(ki - pi, 10 + pi - ki);
    }
    cout << cnt;
}
