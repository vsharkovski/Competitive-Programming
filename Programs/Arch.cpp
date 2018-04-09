#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int brojP = 0;
    int brPC = 0;
    while (n--) {
        int a;
        cin >> a;
//        cout << "brojot " << a << " e ";
        bool ok = true;
        int cbrPC = 0;
        while (a != 0) {
            int cif = a % 10;
            a /= 10;
            if (cif % 2 == 1) {
//                cout << " (cif " << cif << " e losa) ";
                ok = false;
                break;
            } else {
//                cout << " (cif " << cif << " e dobra) ";
                ++cbrPC;
            }
        }
//        cout << ok << enz`dl;
        if (ok) {
            ++brojP;
            brPC += cbrPC;
        }
    }
    cout << brojP << endl << brPC << endl;
}