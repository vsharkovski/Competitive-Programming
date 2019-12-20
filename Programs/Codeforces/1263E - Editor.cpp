#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int M = 1 << 20;

struct node {
    int sum, minpref, maxpref;
    node() {
        sum = 0;
        minpref = 0;
        maxpref = 0;
    }
    void merge(node& l, node& r) {
        sum = l.sum + r.sum;
        minpref = min(l.minpref, l.sum + r.minpref);
        maxpref = max(l.maxpref, l.sum + r.maxpref);
    }
};

node tree[2*M];

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v].sum = tree[v].minpref = tree[v].maxpref = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2*v, tl, tm, pos, val);
        } else {
            update(2*v+1, tm+1, tr, pos, val);
        }
        tree[v].merge(tree[2*v], tree[2*v+1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int pos = 1;
    while (n--) {
        char ch;
        cin >> ch;
        if (ch == 'L') {
            if (pos > 1) {
                --pos;
            }
        } else if (ch == 'R') {
           ++pos;
        } else if (ch == '(') {
            update(1, 1, M, pos, 1);
        } else if (ch == ')') {
            update(1, 1, M, pos, -1);
        } else {
            update(1, 1, M, pos, 0);
        }
        if (tree[1].sum == 0 && tree[1].minpref >= 0) {
            cout << tree[1].maxpref << ' ';
        } else {
            cout << -1 << ' ';
        }
    }
}
