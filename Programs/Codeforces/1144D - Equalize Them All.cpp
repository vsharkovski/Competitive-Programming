#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(200005, 0);
    int best = 200003;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        if (cnt[a[i]] > cnt[best]) {
            best = a[i];
        }
    }
    cout << n - cnt[best] << '\n';
    int lastbestpos = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == best) {
            lastbestpos = i;
            for (int j = i-1; j >= 0 && a[j] != best; --j) {
                if (a[j] < best) {
                    cout << "1 " << j+1 << " " << j+2 << "\n";
                } else {
                    cout << "2 " << j+1 << " " << j+2 << "\n";
                }
            }
        }
    }
    for (int j = lastbestpos+1; j < n; ++j) {
        if (a[j] < best) {
            cout << "1 " << j+1 << " " << j << "\n";
        } else {
            cout << "2 " << j+1 << " " << j << "\n";
        }
    }
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
