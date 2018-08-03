#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string ns; cin >> ns;
    int len = ns.length();
    multiset<int> cif;
    for (int i = 0; i < len; ++i) {
        cif.insert( ns.at(i) - '0' );
    }
    if (*cif.begin() == *prev(cif.end())) {
        cout << 0 << endl;
    } else {
        vector<int> dmg(len, 0);
        vector<int> dgm(len, 0);
        {
            int i = 0;
            for (auto it = cif.begin(); it != cif.end(); ++it) {
                dmg[i] = *it;
                dgm[len-i-1] = *it;
                i++;
            }
        }
        vector<int> dr(len, 0);
        int leftover = 0;
        for (int i = len-1; i >= 0; --i) {
            int r;
            dmg[i] += leftover;
            if (dgm[i] < dmg[i]) {
                r = 10 + dgm[i] - dmg[i];
                leftover = 1;
            }
            else {
                r = dgm[i] - dmg[i];
                leftover = 0;
            }
            dr[i] = r;
            //cout << "i:" << i << " dmg[i]:" << dmg[i] << " dgm[i]:" << dgm[i] << " r:" << r << " le:" << leftover << endl;
            //cout << "\t";
            //for (int i : dr) cout << i;
            //cout << endl;
        }
        if (leftover) dr[0]--;
        bool started = false;
        for (int i : dr) {
            if (i != 0 && !started) {
                started = true;
            }
            if (started) cout << i;
        }
    }
}
