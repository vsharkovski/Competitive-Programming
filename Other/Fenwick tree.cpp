#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


// NOTE; 1-indexed

const int maxn = 100005;


int n;
int a[maxn];
int ft[maxn];

void update(int v, int x) {
    for (; v <= n; v += v & -v) {
        ft[v] += x;
    }
}

int sum(int v) {
    int res = 0;
    for (; v >= 1; v -= v & -v) {
        res += ft[v];
    }
    return res;
}

int sum(int l, int r) {
    return sum(r) - sum(l-1);
}

void Main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        update(i, a[i]);
    }
    while (true) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, x;
            cin >> v >> x;
            update(v, x);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << sum(l, r) << '\n';
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    Main();
}
