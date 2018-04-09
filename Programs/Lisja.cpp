#include <iostream>
using namespace std;
 
int main() {
    int dmax, lmax=-1;
    for (int i = 0; i < 30; ++i) {
        int d, l; cin >> d >> l;
        if (l > lmax) {
            dmax = d;
            lmax = l;
        }
    }
    cout << dmax << " noemvri" << endl;
}