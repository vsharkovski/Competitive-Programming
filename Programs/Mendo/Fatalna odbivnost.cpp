#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    int ans = 0;
 
    while (true) {
        bool did = false;
        for (int i = 0; i+1 < n; ++i) {
            if (a[i] == 1 && a[i+1] == 2) {
                swap(a[i], a[i+1]);
                ++ans;
                did = true;
            }
        }
        if (!did) break;
    }
 
    cout << ans << endl;
 
}
