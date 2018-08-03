#include <iostream>
 
using namespace std;
 
int main() {
    int k[5] = {};
 
    for (int i = 0; i < 5; i++) {
        cin >> k[i];
    }
 
    int s;
    cin >> s;
    s--;
 
    int zbir = 0, odzemeno = 0;
 
    for (int x = s - 1; x >= 0; x--) {
        //cout << "x:" << x << " k[x]:" << k[x] << endl;
        zbir += k[x];
    }
 
    if (zbir >= 1 && zbir <= 5) {
        odzemeno = 20;
    } else if (zbir >= 6 && zbir <= 20) {
        odzemeno = 40;
    } else if (zbir > 20) {
        odzemeno = 50;
    }
 
    cout << 100 - odzemeno << endl;
 
    return 0;
}
