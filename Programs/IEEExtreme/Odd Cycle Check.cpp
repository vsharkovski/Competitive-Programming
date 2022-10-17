#include <bits/stdc++.h>
using namespace std;

// functions used to comunicate with the interactor (the other program)
// use this to get the position of the other player.
// after using it you must do your own move
// TL;DR GetEdge() GetEdge() is invalid
pair<int, int> GetEdge() {
    int a, b; 
    cin >> a >> b;
    return {a, b};
}

// use this to set your answer
void SetAnswer(int s) {
    cout << s << endl;
    if (s == 0) {
        exit(0);
    }
}


const int N = 20010;

struct NodeSetColorData {
    int s, c, copp;
    NodeSetColorData(int _s, int _c, int _copp)
        : s(_s), c(_c), copp(_copp) {}
    string toString() const {
        stringstream ss;
        ss << "(s=" << s << ",c=" << c << ",copp=" << copp << ")";
        return ss.str();
    }
};

struct ColorDSU {
    int p[2*N], rank[2*N];
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            rank[i] = 1;
        }
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline int unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return x;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        p[y] = x;
        return x;
    }
} colorSets;

struct SetDSU {
    int p[N], rank[N];
    pair<int, int> colors[N];
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            rank[i] = 1;
            colors[i] = {2*i, 2*i+1};
        }
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    NodeSetColorData getData(int x) {
        int s = get(x);
        int setc1 = colorSets.get(colors[s].first);
        int setc2 = colorSets.get(colors[s].second);
        int c = colorSets.get(2*x);
        int copp = c == setc1 ? setc2 : setc1;
        return NodeSetColorData(s, c, copp);
    }
    inline void unite(NodeSetColorData dx, NodeSetColorData dy) {
        // if (rank[dx.s] < rank[dy.s]) {
        //     swap(dx, dy);
        // }
        // if (rank[dx.s] == rank[dy.s]) {
        //     ++rank[dx.s];
        // }
        // cout << "uniting dx=" << dx.toString() << " dy=" << dy.toString() << endl;
        // cout << "ranks: " << rank[dx.s] << ", " << rank[dy.s] << endl;
        // if (dx.c == dy.c) {
        //     colors[dx.s].first = colorSets.unite(dx.c, dy.copp);
        //     colors[dx.s].second = colorSets.unite(dx.copp, dy.c);
        // } else {
        //     colors[dx.s].first = colorSets.unite(dx.c, dy.c);
        //     colors[dx.s].second = colorSets.unite(dx.copp, dy.copp);
        // }
        colors[dx.s].first = colorSets.unite(dx.c, dy.copp);
        colors[dx.s].second = colorSets.unite(dx.copp, dy.c);
        // merge sets
        p[dy.s] = dx.s;
        
        // cout << "final: " << getData(dx.s).toString() << endl;
    }
} sets;


int n;
vector<int> adj[N];

int main() {
    // use this to pass the first example
    cin >> n;
    sets.init(n);
    colorSets.init(2*n);
    while (true) {
        auto edge = GetEdge();
        int a = edge.first - 1, b = edge.second - 1;
        
        auto da = sets.getData(a), db = sets.getData(b);
        // cout << endl << "a=" << a << " da=" << da.toString() << endl;
        // cout << "b=" << b << " db=" << db.toString() << endl;
        
        if (da.s == db.s) {
            // same set
            // cout << "same set" << endl;
            if (da.c == db.c) {
                // same colors, stop
                // cout << "same colors" << endl;
                SetAnswer(0);
            } else {
                SetAnswer(1);
            }
        } else {
            // different sets, merge sets and colors
            // cout << "diff sets, uniting" << endl;
            sets.unite(da, db);
            SetAnswer(1);
        }
        // cout << "data for each node:" << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << "i=" << i << " di=" << sets.getData(i).toString() << endl;
        // }
    }
    return 0;
}
