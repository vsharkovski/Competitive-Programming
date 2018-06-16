#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    long long zbir = 0;
    int najmalneparen = 1e9+2;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x & 1) {
            najmalneparen = min(najmalneparen, x);
        }
        zbir += x;
    }
    if (zbir & 1) {
        zbir -= najmalneparen;
    }
    cout << zbir;
}
