#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



struct DSU {
    int n;
    vector<int> p, rank;
    DSU(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                ++rank[y];
            }
        }
        return true;
    }
};

const int maxn = 50005;
const int unset = -2*maxn;

int n;
int a[maxn], b[maxn];

int variables;
int value[maxn];
map<string, int> vid;
DSU dsu(maxn);

int getid(string& s) {
    if (vid.count(s)) {
        return vid[s];
    } else {
        return vid[s] = variables++;
    }
}

void read(int arr[maxn]) {
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] >= 'a' && s[0] <= 'z') {
            arr[i] = getid(s);
        } else {
            arr[i] = -stoi(s);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    variables = 0;
    read(a);
    read(b);
    fill(value, value+maxn, unset);

    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            a[i] = dsu.get(a[i]);
        }
        if (b[i] >= 0) {
            b[i] = dsu.get(b[i]);
        }
        if (a[i] < 0 && b[i] < 0) {
            if (a[i] != b[i]) {
                cout << "NE\n";
                return 0;
            }
        } else if (a[i] >= 0 && b[i] >= 0) {
            if (value[a[i]] == unset && value[b[i]] == unset) {
                dsu.unite(a[i], b[i]);
            } else if (value[a[i]] == unset && value[b[i]] != unset) {
                value[a[i]] = value[b[i]];
            } else if (value[a[i]] != unset && value[b[i]] == unset) {
                value[b[i]] = value[a[i]];
            } else if (value[a[i]] != value[b[i]]) {
                cout << "NE\n";
                return 0;
            }
        } else {
            if (a[i] < 0) {
                swap(a[i], b[i]);
            }
            // a[i] is variable, b[i] is constant
            if (value[a[i]] == unset) {
                value[a[i]] = b[i];
            } else if (value[a[i]] != b[i]) {
                cout << "NE\n";
                return 0;
            }
        }
    }

    cout << "DA\n";

}
