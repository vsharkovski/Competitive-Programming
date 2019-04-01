#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



int a[20];

int dfs(int l, int r) {
    bool sorted = true;
    for (int i = l+1; i < r; ++i) {
        if (a[i-1] > a[i]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        return r - l;
    } else {
        int m = (l + r) / 2;
        return max(dfs(l, m), dfs(m, r));
    }
}

void Main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = dfs(0, n);
    cout << ans << '\n';
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
