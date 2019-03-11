#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





struct Node {
    ll yy, yn, ny, nn;
    Node() {
        yy = yn = ny = nn = 0;
    }
};

int n;
Node tree[150000];

void merge(Node& nd, Node& l, Node& r) {
    nd.yy = max(l.yy + r.ny, l.yn + r.yy);
    nd.yn = max(l.yy + r.nn, l.yn + r.yn);
    nd.ny = max(l.ny + r.ny, l.nn + r.yy);
    nd.nn = max(l.ny + r.nn, l.nn + r.yn);
}

void build() {
    for (int k = n-1; k >= 1; --k) {
        merge(tree[k], tree[2*k], tree[2*k+1]);
    }
}

void update(int k, int x) {
    k += n;
    tree[k].yy = x;
    tree[k].yn = tree[k].ny = tree[k].nn = 0;
    for (k /= 2; k >= 1; k /= 2) {
        merge(tree[k], tree[2*k], tree[2*k+1]);
    }
}

void Main() {
    int m, d;
    cin >> m >> d;
    n = 1;
    while (n < m) n *= 2;
    for (int i = 0; i < m; ++i) {
        cin >> tree[i + n].yy;
    }
    build();
    ll answer = 0;
    while (d--) {
        int i, x;
        cin >> i >> x;
        --i;
        update(i, x);
        answer += tree[1].yy;
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
        freopen("optmilk.in", "r", stdin);
        freopen("optmilk.out", "w", stdout);
    #endif
    Main();
    return 0;
}
