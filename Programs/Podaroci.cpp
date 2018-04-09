#include <bits/stdc++.h>
using namespace std;
 
struct p {
    int d, s;
};
 
int main() {
    int dk, sk, n; cin >> dk >> sk >> n;
    vector<p> poss;
    for (int i = 0; i < n; ++i) {
        int d, s; cin >> d >> s;
        if ((d <= dk && s <= sk) || (s <= dk && d <= sk)) {
            poss.push_back({d, s});
            continue;
        }
    }
    cout << poss.size() << endl;
    for (p _p : poss) {
        cout << _p.d << " " << _p.s << endl;
    }
}