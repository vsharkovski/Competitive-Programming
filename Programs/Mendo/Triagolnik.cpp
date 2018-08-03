#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int s[] = {a, b, c};
    int minR = 10000000;
    for (int i = 0; i < 3; ++i) {
        int c = 0;
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            c += abs(s[j] - s[i]);
        }
        if (c < minR) minR = c;
    }
    cout << minR*10;
}
