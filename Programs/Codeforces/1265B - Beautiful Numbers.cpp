#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), nxtL(n), nxtR(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            b[a[i]] = i;
            nxtL[i] = i-1;
            nxtR[i] = i+1;
        }
        for (int x = 0; x < n; ++x) {
            int i = b[x];
            int j = i;
            while (j >= 0 && a[j] <= x) {
                j = nxtL[j];
            }
            int L = j;
            j = i;
            while (j < n && a[j] <= x) {
                j = nxtR[j];
            }
            int R = j;
            if (L != -1) {
                nxtR[L] = R;
            }
            if (R != n) {
                nxtL[R] = L;
            }
            if (R-L-1 == x+1) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}
