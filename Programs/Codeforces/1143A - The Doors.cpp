#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int n, tot0 = 0, tot1 = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) ++tot1; else ++tot0;
    }
    int op0 = 0, op1 = 0;
    for (int i = 0; i < n; ++i) {
        if (op0 == tot0 || op1 == tot1) {
            cout << i << '\n';
            return;
        }
        if (a[i]) ++op1; else ++op0;
    }
    cout << n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
