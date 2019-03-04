#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



void Main() {
    int m, d, n;
    cin >> m >> d >> n;
    int ans = 1;
    int h = 0;
    while (h < m) {
        h += d;
        if (h >= m) break;
        h -= n;
        ++ans;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
