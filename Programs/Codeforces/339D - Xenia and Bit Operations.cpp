#include <bits/stdc++.h>
using namespace std;

const int N = 17;

int n, m;
int a[1<<N];
int tree[1<<(N+1)];
bool opt[1<<(N+1)];
bool base;

inline void merge(bool b, int& v, int& l, int& r) {
    if (base ^ b) {
        v = l | r;
    } else {
        v = l ^ r;
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        opt[2*v] = !opt[v];
        build(2*v, tl, tm);
        opt[2*v+1] = !opt[v];
        build(2*v+1, tm+1, tr);
        merge(opt[v], tree[v], tree[2*v], tree[2*v+1]);
    }
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2*v, tl, tm, pos, val);
        } else {
            update(2*v+1, tm+1, tr, pos, val);
        }
        merge(opt[v], tree[v], tree[2*v], tree[2*v+1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < (1 << n); ++i) {
        cin >> a[i];
    }
    base = n % 2 == 1;
    opt[0] = true;
    build(1, 0, (1<<n)-1);
    while (m--) {
        int p, b;
        cin >> p >> b;
        --p;
        update(1, 0, (1<<n)-1, p, b);
        cout << tree[1] << endl;
    }
}
