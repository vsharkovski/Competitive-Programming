#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;






void Main() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int d = -1000; d <= 1000; ++d) {
        if (d == 0) continue;
        int numpos = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] / double(d) > 0) {
                ++numpos;
            }
        }
        int need = n / 2 + !!(n%2);
        if (numpos >= need) {
            cout << d << '\n';
            return;
        }
    }
    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
