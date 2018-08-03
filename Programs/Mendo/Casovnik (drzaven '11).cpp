#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int t1 = h1*60+m1, t2 = h2*60+m2;
    int d = min( abs(t1-t2) , min( abs(t1-(t2+1440)) , abs((t1+1440)-t2) ));
    int cnt = 0;
    while (d > 0) {
        if (d >= 60) {
            cnt++;
            d -= 60;
        } else {
            cnt += min(d, 1+(60-d));
            d = 0;
        }
    }
    cout << cnt << '\n';


}
