#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());

    int br = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt >= n) {
            break;
        }
        cnt += a[i]+1;
        br++;
    }
    cout << br;


}
