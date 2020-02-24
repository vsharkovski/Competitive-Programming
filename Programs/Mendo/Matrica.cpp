#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    if (x >= 1 && x <= h && y >= 1 && y <= w) {
        cout << "DA";
    } else {
        cout << "NE";
    }
}
