#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 100100;
const int M = 1<<18;

int n;
int basearr[N];
int sum[M];
int lazy[M];

void build(int v, int tl, int tr) {
    lazy[v] = 2;
    if (tl == tr) {
        sum[v] = basearr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        sum[v] = sum[2*v] + sum[2*v+1];
    }
    //cout<<"NODE(v="<<v<<",tl="<<tl<<",tr="<<tr<<",sum="<<sum[v]<<")\n";
}

inline void push(int v, int tl, int tr) {
    if (lazy[v] == 2) {
        return;
    } else if (lazy[v] == 0) {
        sum[2*v] = sum[2*v+1] = 0;
        lazy[2*v] = lazy[2*v+1] = 0;
    } else if (lazy[v] == 1) {
        int tm = (tl + tr) / 2;
        sum[2*v] = tm - tl + 1;
        sum[2*v+1] = tr - tm;
        lazy[2*v] = lazy[2*v+1] = 1;
    }
    lazy[v] = 2;
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    //cout << "Q(v="<<v<<",tl="<<tl<<",tr="<<tr<<",l="<<l<<",r="<<r<<")\n";
    if (l <= tl && tr <= r) {
        //cout<<"--> sum="<<sum[v]<<'\n';
        return sum[v];
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    return  query(2*v, tl, tm, l, min(r, tm))
            + query(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void assign(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return;
    if (l == tl && tr == r) {
        lazy[v] = x;
        if (x == 0) sum[v] = 0;
        else sum[v] = tr - tl + 1;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    assign(2*v, tl, tm, l, min(r, tm), x);
    assign(2*v+1, tm+1, tr, max(l, tm+1), r, x);
    sum[v] = sum[2*v] + sum[2*v+1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; ++i) {
        cin >> basearr[i];
    }
    build(1, 1, n);
    while (Q--) {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        //cout << "l=" << l << " r=" << r << " ";
        if (ch == '+') {
            assign(1, 1, n, l, r, 1);
            //cout << "assigning 1\n";
        } else if (ch == '-') {
            assign(1, 1, n, l, r, 0);
            //cout << "assigning 0\n";
        } else {
            //cout << "sum=";
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}
