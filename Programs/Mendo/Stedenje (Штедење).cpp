#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int k, a, b;
    cin >> k >> a >> b;
    if (a >= b || k % (b - a) != 0) {
        cout << "NE\n";
        return 0;
    }
    cout << k / (b - a);
 
}
