#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, t;
    cin >> p >> t;
    int x = 2*60*p + 4*60*t;
    cout << 10000-x;
}
