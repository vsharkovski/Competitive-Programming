#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    map<int, int> counts;
    while (n != 0) {
        int c = n % 10;
        if (c == 9) {
            c = 6;
        }
        counts[c]++;
        n /= 10;
    }
    if (counts[6] % 2 == 1) {
        counts[6] = counts[6]/2 + 1;
    }
    else {
        counts[6] /= 2;
    }
    int cm = -1;
    for (int i = 0; i < 10; ++i) {
        if (counts[i] > cm) {
            cm = counts[i];
        }
    }
    cout << cm << endl;
}