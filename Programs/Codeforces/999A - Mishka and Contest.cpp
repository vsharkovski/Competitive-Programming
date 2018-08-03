#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int a = 0, b = n-1, cnt = 0;
    for (a = 0; a < n; ++a) {
        if (v[a] > k) {
            break;
        } else {
            cnt++;
        }
    }
    for (b = n-1; b > a; --b) {
        if (v[b] > k) {
            break;
        }else {
            cnt++;
        }
    }
    cout << cnt;

}
