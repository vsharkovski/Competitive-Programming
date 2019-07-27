#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18;
const int mod = 1e9 + 7;
const int maxn = 200010;

int n;
pii dolls[maxn];

struct Node {
    Node *l, *r;
    int tl, tr, tm;
    
    ll minval;
    int ways;

    Node() {}
    Node(int treel, int treer) {
        init(treel, treer);
    }
    void init(int treel, int treer) {
        tl = treel;
        tr = treer;
        build();
    }
    void merge() {
        if (l->minval < r->minval) {
            minval = l->minval;
            ways = l->ways;
        } else if (l->minval > r->minval) {
            minval = r->minval;
            ways = r->ways;
        } else {
            minval = l->minval;
            ways = (l->ways + r->ways) % mod;
        }
    }
    void build() {
        if (tl == tr) {
            minval = inf;
            ways = 0;
        } else {
            tm = (tl + tr) / 2;
            l = new Node(tl, tm);
            r = new Node(tm+1, tr);
            merge();
        }
    }
    void update(int pos, ll val, ll ways) {
        if (tl == tr) {
            this->minval = val;
            this->ways = ways;
        } else {
            if (pos <= tm) {
                l->update(pos, val, ways);
            } else {
                r->update(pos, val, ways);
            }
            merge();
        }
    }
    pair<ll, int> query(int i) {
        if (dolls[tr].first < dolls[i].second) return pll(inf, 0);
        if (dolls[i].second <= dolls[tl].first) return pll(minval, ways);
        auto res1 = l->query(i);
        auto res2 = r->query(i);
        if (res1.first < res2.first) {
            return res1;
        } else if (res2.first < res1.first) {
            return res2;
        } else {
            return pair<ll, int>(res1.first, (res1.second + res2.second) % mod);
        }
    }
} tree;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dolls[i].second >> dolls[i].first;
    }
    sort(dolls, dolls+n, [&] (pii& a, pii& b) {
        return a.first != b.first ? a.first < b.first : a.second < b.second;
    });
    tree.init(0, n-1);
    for (int i = n-1; i >= 0; --i) {
        auto res = tree.query(i);
        if (res.first == inf) {
            tree.update(i, dolls[i].first, 1);
        } else {
            tree.update(i, dolls[i].first - dolls[i].second + res.first, res.second);
        }
    }
    cout << tree.ways << '\n';
}

