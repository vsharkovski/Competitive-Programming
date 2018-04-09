#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int ne = n % 10;
    int nd = n / 10;
 
    int t = 10 * ne + nd;
    int b = n + t;
 
    cout << b << endl;
}