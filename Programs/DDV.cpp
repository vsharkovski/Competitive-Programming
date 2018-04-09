#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
 
using namespace std;
 
int main() {
    string ime;
    double c;
    int n;
    cin >> ime >> c >> n;
 
    vector<string> ddv5;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        ddv5.push_back(x);
    }
 
    bool ddv18 = true;
 
    for (unsigned int i = 0; i < (unsigned)n; i++) {
        if (ddv5[i] == ime) {
            ddv18 = false;
            break;
        }
    }
 
    double cena = ddv18 ? c * 1.18 : c * 1.05;
 
    cout << setprecision(5) << fixed << cena << endl;
 
    return 0;
}