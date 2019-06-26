#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int maxn = 1e6 + 5;
const int maxprice = 1e6 + 5;
const ll inf = 1e16;


int n, k, m;
vector<pii> events[maxn];

struct Node {
    ll cores; //total
    ll totalprice;
    ll maxprice;
    Node() {
        cores = 0;
        totalprice = 0;
        maxprice = 0;
    }
    Node(ll c, ll tp, ll mp) {
        cores = c;
        totalprice = tp;
        maxprice = mp;
    }
};

static Node tree[4*maxprice];

void merge(Node& v, Node& l, Node& r) {
    v.cores = l.cores + r.cores;
    v.totalprice = l.totalprice + r.totalprice;
    v.maxprice = max(l.maxprice, r.maxprice);
}

void update(int v, int tl, int tr, int price, int cores) {
    if (tl == tr) {
        tree[v].cores += cores;
        tree[v].totalprice += ll(cores)*price;
        if (tree[v].cores > 0) {
            tree[v].maxprice = price;
        } else {
            tree[v].maxprice = 0;
        }
    } else {
        int tm = (tl + tr) / 2;
        if (price <= tm) {
            update(2*v, tl, tm, price, cores);
        } else {
            update(2*v+1, tm+1, tr, price, cores);
        }
        merge(tree[v], tree[2*v], tree[2*v+1]);
    }
}

struct QueryResult {
    ll totalprice, maxprice;
    QueryResult(ll tp, ll mp) {
        totalprice = tp;
        maxprice = mp;
    }
    QueryResult() {}
};

QueryResult query(int v, int tl, int tr, int want) {
    if (tree[v].cores < want) {
        return QueryResult(-inf, inf);
    } else if (tree[v].cores == want) {
        return QueryResult(tree[v].totalprice, tree[v].maxprice);
    } else if (tl == tr) {
        return QueryResult(ll(tl) * want, tl);
    } else {
        int tm = (tl + tr) / 2;
        if (tree[2*v].cores >= want) {
            return query(2*v, tl, tm, want);
        } else {
            QueryResult res2 = query(2*v+1, tm+1, tr, want - tree[2*v].cores);
            return QueryResult(tree[2*v].totalprice + res2.totalprice, res2.maxprice);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < m; ++i) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        events[l].emplace_back(p, c);
        events[r+1].emplace_back(p, -c);
    }
    ll ans = 0; // final answer
    ll totalcores = 0;
    ll totalprice = 0; // if taking all cores
    QueryResult q(0, 0);
    for (int i = 1; i <= n; ++i) {
        ll prevtotalcores = totalcores;
        int minpricechange = 1e9;
        for (auto& event : events[i]) {
            int p = event.first;
            int c = event.second;
            update(1, 0, maxprice-1, p, c);
            totalcores += c;
            totalprice += ll(p) * c;
            minpricechange = min(minpricechange, p);
        }
        bool shouldquery = false;
        if (prevtotalcores < k) {
            if (totalcores >= k) {
                shouldquery = true;
            }  else {
                shouldquery = false;
            }
        } else if (totalcores < k) {
            shouldquery = false;
        } else if (minpricechange <= q.maxprice) {
            shouldquery = true;
        } else {
            shouldquery = false;
        }
        if (totalcores < k) { // can't use query
            ans += totalprice;
        } else {
            if (shouldquery) { // get new query result
                q = query(1, 0, maxprice-1, k);
            }
            ans += q.totalprice;
        }
    }
    cout << ans << '\n';
}
