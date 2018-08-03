#include <bits/stdc++.h>
using namespace std;
 
bool F() {
    int a[9];
    for (int i = 0; i < 9; ++i) {
        char c;
        cin >> c;
        a[i] = c-'0';
    }
//310456316
    int den = 10*a[0] + a[1];
    int mesec = 10*a[2] + a[3];
    int godina = 100*a[4] + 10*a[5] + a[6];
    godina = godina < 600 ? godina + 2000 : godina + 1000;
    int avtor = a[7]; //
    int ostatok = a[8]; //
 
    if (avtor != 1 && avtor != 6 && avtor != 9) {
//        cout << "greska so avtorot\n";
        return false;
    }
 
    int ostatok1 = (a[0]*a[0]+a[1]*a[1]+a[2]*a[2]+a[3]*a[3]+a[4]*a[4]+a[5]*a[5]+a[6]*a[6]+a[7]*a[7]) % 7;
    if (ostatok1 != ostatok) {
//        cout << "greska so ostatokot\n";
        return false;
    }
 
    if (den == 0) return false;
    if (mesec == 2) {
        bool prestapna = godina%4 == 0;
        if (godina%100 == 0 && godina%400 != 0) prestapna = 0;
        if (!prestapna && den == 29) {
//            cout << "greska so prestapnost\n";
            return false;
        }
    } else {
        int mdp[11][2] = {{1, 31},{3, 31},{4, 30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        bool found = 0;
        for (int i = 0; i < 11; ++i) {
            if (mdp[i][0] == mesec && mdp[i][1] >= den) {
                found = 1;
                break;
            }
        }
        if (!found) {
//            cout << "greska so broj na denovi\n";
            return false;
        }
    }
 
    return true;
}
 
int main() {
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        cout << F() << endl;
    }
}
