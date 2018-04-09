#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, b;
    cin >> a >> b;
    cout << 1 << endl;
    if (a > b) swap(a, b);
    for (int i = 2; i <= b; ++i) {
        if (a % i == 0 && b % i == 0) {
            cout << i << endl;
        }
    }
}