#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const int maxn = 100005;

int n, m;
ll a[maxn];
ll st_sum[4*maxn];
ll st_max[4*maxn];

void build(int k, int x, int y) {
    if (x == y) {
        st_sum[k] = a[x];
        st_max[k] = a[x];
    } else {
        int d = (x + y) / 2;
        build(2*k, x, d);
        build(2*k+1 , d+1, y);
        st_sum[k] = st_sum[2*k] + st_sum[2*k+1];
        st_max[k] = max(st_max[2*k], st_max[2*k+1]);
    }
}

ll getsum(int k, int x, int y, int a, int b) {
    if (a > y || b < x) return 0;
    if (a <= x && y <= b) return st_sum[k];
    int d = (x + y) / 2;
    return getsum(2*k, x, d, a, b) + getsum(2*k+1, d+1, y, a, b);
}

void updatevalue(int k, int x, int y, int idx, int val) {
//    cout << "updatevalue(" << k << ", " << x << ", " << y << ", " << idx << ", " << val << ")\n";
    if (x == y) {
        st_sum[k] = val;
        st_max[k] = val;
    } else {
        int d = (x + y) / 2;
        if (idx <= d) {
            updatevalue(2*k, x, d, idx, val);
        } else {
            updatevalue(2*k+1, d+1, y, idx, val);
        }
        st_sum[k] = st_sum[2*k] + st_sum[2*k+1];
        st_max[k] = max(st_max[2*k], st_max[2*k+1]);
    }
}

void makemod(int k, int x, int y, int a, int b, int mod) {
//    cout << "makemod(" << k << ", " << x << ", " << y << ", " << a << ", " << b << ", " << mod << ")\n";
    if (a > y || b < x || st_max[k] < mod) {
//        cout << "returning\n";
        return;
    } if (x == y) {
        st_sum[k] %= mod;
        st_max[k] = st_sum[k];
//        cout << "setting sum[" << k << "] to " << st_sum[k] << "\n";
    } else {
        int d = (x + y) / 2;
//        cout << "going to children\n";
        makemod(2*k, x, d, a, b, mod);
        makemod(2*k+1, d+1, y, a, b, mod);
        st_sum[k] = st_sum[2*k] + st_sum[2*k+1];
        st_max[k] = max(st_max[2*k], st_max[2*k+1]);
    }
}

void Main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n-1);
    while (m--) {
//        cout << "\n";
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
//            cout << "sum[" << l << ", " << r << "] = ";
            cout << getsum(1, 0, n-1, l, r) << '\n';
        } else if (t == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
//            cout << "mod[" << l << ", " << r << ", " << x << "]\n";
            makemod(1, 0, n-1, l, r, x);
        } else {
            int k, x;
            cin >> k >> x;
            --k;
//            cout << "setting a[" << k << "] = " << x << "\n";
            updatevalue(1, 0, n-1, k, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
