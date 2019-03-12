#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;







void Main() {
    int n;
    cin >> n;
    map<int, int> cnt;
    set<int> uniq;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
        uniq.insert(a);
    }
    int ans = 0;
    for (int x : uniq) {
        int res = 0;
        for (int y = x; y <= x+5; ++y) {
            res += cnt[y];
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
