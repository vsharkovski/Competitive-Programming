#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int s, k;
    cin >> s >> k;
    map<int, int> m;
    for (int i = s; i <= k; ++i) {
        int i1 = i;
        while (i1 != 0) {
            m[i1 % 10]++;
            i1 /= 10;
        }
    }
    for (int i = 0; i < 10; ++i) cout << m[i] << " ";
}
