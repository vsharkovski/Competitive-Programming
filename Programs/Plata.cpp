#include <bits/stdc++.h>
using namespace std;
 
int main() {
    double p1, p2, p3;
    cin >> p1 >> p2 >> p3;
 
    if (p3/p2 == p2/p1) {
        cout << p3 * (p3/p2);
    }
    else {
        cout << p3 + (p3 - p2);
    }
 
}