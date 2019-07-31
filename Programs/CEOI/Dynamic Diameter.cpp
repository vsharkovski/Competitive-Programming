#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18;
const int maxn = 100010;
const int maxq = 100010;



int n, q;
ll max_weight;
vector<int> adj[maxn];

struct Edge {
    int u, v;
    ll w;
    vector<pii> intrees; // in which centroids' segment trees it is in, also the lower node

    inline int other(int nd) {
        return nd == u ? v : u;
    }
} edges[maxn];

struct Node {
    Node *ln, *rn;
    int tl, tr;

    ll maxval;
    ll lazy;

    Node() {}

    void init(int treel, int treer, vector<ll> &vec) {
        tl = treel;
        tr = treer;
        build(vec);
    }

    inline void push() {
        ln->maxval += lazy;
        ln->lazy += lazy;
        rn->maxval += lazy;
        rn->lazy += lazy;
        lazy = 0;
    }

    inline void merge() {
        maxval = max(ln->maxval, rn->maxval);
    }

    void build(vector<ll> &vec) {
        lazy = 0;
        if (tl == tr) {
            maxval = vec[tl];
        } else {
            int tm = (tl + tr) / 2;
            ln = new Node();
            rn = new Node();
            ln->init(tl, tm, vec);
            rn->init(tm+1, tr, vec);
            merge();
        }
        // cout << "tl=" << tl << " tr=" << tr << " maxval=" << maxval << endl;
    }

    void update(int l, int r, ll val) {
        if (l > r) {
            return;
        }
        if (l <= tl && tr <= r) {
            maxval += val;
            lazy += val;
            return;
        }
        push();
        ln->update(l, min(r, ln->tr), val);
        rn->update(max(l, rn->tl), r, val);
        merge();
    }

    ll query(int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l <= tl && tr <= r) {
            return maxval;
        }
        push();
        return max(ln->query(l, min(r, ln->tr)),
                   rn->query(max(l, rn->tl), r));
    }

    void set_single(int i, ll val) {
        if (tl == tr) {
            maxval = val;
            lazy = 0;
            return;
        }
        if (i <= ln->tr) {
            ln->set_single(i, val);
        } else {
            rn->set_single(i, val);
        }
        merge();
    }
} trees[maxn]; // segment tree for each centroid

// segment tree for the array a[centroid] = max length of path
// going through centroid, all nodes are in centroid's subtree
Node best_path;

bool removed[maxn];
int sbsz_cdecompose[maxn];

int num_calls;
unordered_map<int, int> label[maxn]; // dfs reordering for each centroid's subtree
vector<int> sbsz[maxn]; // subtree size for each node in each centroid's subtree
vector<int> panc[maxn];
multiset<ll> panc_data[maxn];

int dfs_centroid(int centroid, vector<ll> &distances, int u, int p, ll dist, int p2) {
    distances.push_back(dist);
    int label_u = num_calls++;
    label[centroid][u] = label_u;
    sbsz[centroid].push_back(1);
    if (p2 == -1 && u != centroid) {
        p2 = label_u;
    }
    panc[centroid].push_back(p2);
    for (int i : adj[u]) {
        int v = edges[i].other(u);
        if (v != p && !removed[v]) {
            edges[i].intrees.emplace_back(centroid, v);
            int label_v = dfs_centroid(centroid, distances, v, u, dist + edges[i].w, p2);
            sbsz[centroid][label_u] += sbsz[centroid][label_v];
        }
    }
    // cout << "dfs(u=" << u << ", dist=" << dist << ", p2=" << p2 << ") label=" << label_u << " sbsz=" << sbsz[centroid][label_u] << " dist=" << distances[label_u] << "\n";
    return label_u;
}

inline void get_centroid_best_path(int centroid) {
    ll res = 0;
    int i = 0;
    for (auto it = panc_data[centroid].rbegin(); i < 2 && it != panc_data[centroid].rend(); ++i, ++it) {
        res += *it;
    }
    // cout << "panc data for centroid=" << centroid << ": ";
    // for (auto it = panc_data[centroid].begin(); it != panc_data[centroid].end(); ++it) {
    //     cout << *it << ' ';
    // }
    // cout << endl;
    // cout << "best path for centroid=" << centroid << ": " << res << endl;
    best_path.set_single(centroid, res);
}

inline void solve_centroid(int centroid) {
    // cout << "\ncentroid: " << centroid << endl;
    vector<ll> distances;
    num_calls = 0;
    dfs_centroid(centroid, distances, centroid, -1, 0, -1);
    // cout << "distances: "; for (auto x : distances) cout << x << ' '; cout << "\n";
    // cout << "num_calls: " << num_calls << endl;
    trees[centroid].init(0, num_calls-1, distances);
    for (int i : adj[centroid]) {
        int v = edges[i].other(centroid);
        if (!removed[v]) {
            int label_v = label[centroid][v];
            // cout << "child for centroid=" << v << " (label=" << label_v << "), maxdist=" << trees[centroid].query(label_v, label_v + sbsz[centroid][label_v] - 1) << "\n";
            panc_data[centroid].insert(trees[centroid].query(label_v, label_v + sbsz[centroid][label_v] - 1));
        }
    }
    get_centroid_best_path(centroid);
}

void dfs_sbsz_cdecompose(int u, int p) {
    sbsz_cdecompose[u] = 1;
    for (int i : adj[u]) {
        int v = edges[i].other(u);
        if (v != p && !removed[v]) {
            dfs_sbsz_cdecompose(v, u);
            sbsz_cdecompose[u] += sbsz_cdecompose[v];
        }
    }
}

int find_centroid(int u, int p, int sz) {
    for (int i : adj[u]) {
        int v = edges[i].other(u);
        if (v != p && !removed[v] && sbsz_cdecompose[v] > sz/2) {
            return find_centroid(v, u, sz);
        }
    }
    return u;
}

void cdecompose(int root, int parent) {
    dfs_sbsz_cdecompose(root, parent);
    int centroid = find_centroid(root, parent, sbsz_cdecompose[root]);
    solve_centroid(centroid);
    removed[centroid] = true;
    for (int i : adj[centroid]) {
        int v = edges[i].other(centroid);
        if (!removed[v]) {
            cdecompose(v, centroid);
        }
    }
    removed[centroid] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q >> max_weight;
    for (int i = 0; i < n-1; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }
    {
        vector<ll> aux(n+1, 0);
        best_path.init(1, n, aux);
    }
    memset(removed, false, sizeof(removed));
    cdecompose(1, -1);
    ll last = 0;
    while (q--) {
        ll eid, new_w;
        cin >> eid >> new_w;
        eid = (eid + last) % (n-1);
        new_w = (new_w + last) % max_weight;

        ll change = new_w - edges[eid].w;
        // cout << "\neid=" << eid << " new_w=" << new_w << " change=" << change << "\n";
        for (pii& t : edges[eid].intrees) {
            int centroid = t.first;
            int v = t.second;
            int label_v = label[centroid][v];
            int label_p = panc[centroid][label_v];
            ll prev_data = trees[centroid].query(label_p, label_p + sbsz[centroid][label_p] - 1);
            // cout << "centroid=" << centroid << " v=" << v << " label_v=" << label_v << " label_p=" << label_p << " prev_data=" << prev_data << "\n";
            trees[centroid].update(label_v, label_v + sbsz[centroid][label_v] - 1, change);
            panc_data[centroid].erase(panc_data[centroid].find(prev_data));
            panc_data[centroid].insert(trees[centroid].query(label_p, label_p + sbsz[centroid][label_p] - 1));
            get_centroid_best_path(centroid);
        }
        edges[eid].w = new_w;

        last = best_path.maxval;
        cout << last << '\n';
    }
}

