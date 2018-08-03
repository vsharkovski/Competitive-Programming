#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    long long cnt = 0;
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        int j = i;
        while (j > 0) {
            cnt += d[j%10];
            j/=10;
        }
    }

    cout << cnt;
}
