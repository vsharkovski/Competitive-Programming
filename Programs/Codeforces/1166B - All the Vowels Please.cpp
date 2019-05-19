#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int k;
    cin >> k;
    for (int p = 1; p <= k; ++p) {
        if (k % p == 0) {
            int R = p;
            int C = k/p;
            if (R >= 5 && C >= 5) {
                for (int r = 0; r < R; ++r) {
                    for (int c = 0; c < C; ++c) {
                        cout << vowels[(r+c)%5];
                    }
                }
                return 0;
            }
        }
    }
    cout << -1;
}
