#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(5);
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
 
    sort(a.begin(), a.end());
    int x = 100*a[4] + 10*a[3] + a[2];
    cout << x << ' ' << 2*x;
 
}
