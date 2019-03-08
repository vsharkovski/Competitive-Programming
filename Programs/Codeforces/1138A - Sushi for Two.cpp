#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {

    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int len = 1;
    vector<int> v;
    for (int i = 1; i < n; ++i) {
        if (t[i] != t[i-1]) {
            v.push_back(len);
            len = 1;
        } else {
            ++len;
        }
    }
    v.push_back(len);
    int ans = 0;
    for (int i = 1; i < v.size(); ++i) {
        ans = max(ans, 2*min(v[i], v[i-1]));
    }
    cout << ans << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
