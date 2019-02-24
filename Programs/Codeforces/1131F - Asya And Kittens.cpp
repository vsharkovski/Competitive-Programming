#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




struct DSU {
    int n;
    vector<int> p, rank, L, R, Lmst, Rmst;
    DSU(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rank.assign(n, 1);
        L.assign(n, -1);
        R.assign(n, -1);
        Lmst.resize(n);
        Rmst.resize(n);
        iota(Lmst.begin(), Lmst.end(), 0);
        iota(Rmst.begin(), Rmst.end(), 0);
    }
    inline int get(int x) {
        return (p[x] == x) ? (x) : (p[x] = get(p[x]));
    }
    inline bool unite(int x0, int y0) {
//        cout << "uniting x0=" << x0 << " y0=" << y0 << " --> ";
        int x = get(x0), y = get(y0);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            swap(x, y);
            swap(x0, y0);
//            cout << "(swapping) ";
        }
//        cout << "x=" << x << " y=" << y << "\n";
        R[Rmst[x]] = Lmst[y];
        L[Lmst[y]] = Rmst[x];
//        cout << Rmst[x] << " then " << Lmst[y] << "\n";
        Rmst[x] = Rmst[y];
        p[y] = x;
        if (rank[x] == rank[y]) {
            ++rank[y];
        }
        return true;
    }
};

void Main() {
    int n;
    cin >> n;
    DSU dsu(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        dsu.unite(x, y);
    }
//    for (int i = 0; i < n; ++i) {
//        cout << "L[" << i << "] = " << dsu.L[i] << " ; R[" << i << "] = " << dsu.R[i] << "\n";
//    }
    int src;
    for (int i = 0; i < n; ++i) {
        if (dsu.L[i] == -1) {
            src = i;
            break;
        }
    }
    do {
        cout << src+1 << ' ';
        src = dsu.R[src];
    } while (src != -1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
