#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, g;
    vector<int> v(3), p(3);
    cin >> n >> v[0] >> v[1] >> v[2];
    p[0] = p[1] = p[2] = 0;
    vector<int> status(n+1, -1);
    for (int i = 0; i < 3*n + 3; ++i) {
        int j = i % 3;
        p[j] = (p[j] + v[j]) % (n+1);
        if (p[j] != 0) {
            if (status[p[j]] == -1) {
                status[p[j]] = j;
            } else if (status[p[j]] != j) {
                cout << i+1 << '\n';
                return 0;
            }
        }
    }
    cout << (ll)3000000000 << endl;
}
