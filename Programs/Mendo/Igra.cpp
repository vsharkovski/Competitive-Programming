#include <iostream>
 
using namespace std;
 
int main() {
    int n, po_red = 0, najveke = 0;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
 
        if (x == 2) {
            po_red = 0;
        } else {
            po_red++;
        }
 
        if (po_red > najveke) {
            najveke = po_red;
        }
    }
 
    cout << najveke << endl;
 
    return 0;
}
