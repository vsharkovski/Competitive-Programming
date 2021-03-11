#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, r, b;
    cin >> n >> a >> r >> b;
    int cnt1 = n / a;
    n -= cnt1 * a;
    n += cnt1 * r;
    int cnt2 = n / b;
    if (cnt1 < cnt2) {
        cout << "DA\n";
    } else {
        cout << "NE\n";
    }
}
