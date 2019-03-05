#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




int n, m;

inline int getdist(int x, int y) {
    if (y <= x) y += n;
    return y - x;
}

void Main() {
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int x = 0;
    for (int i = 1; i <= n; ++i) {
        sort(v[i].begin(), v[i].end(), [&](int x, int y){
            return getdist(i, x) < getdist(i, y);
        });
        x = max(x, (int)v[i].size());
    }
    int REMOVE = max(0, x - 2);
    int init = n * REMOVE;
    int mnew = 0;
    for (int i = 1; i <= n; ++i) {
//        cout << "v[" << i << "] = "; for (int y : v[i]) cout << y << ' ';
//        cout << "\n";
        for (int j = 0; j < REMOVE; ++j) {
            if (v[i].empty()) break;
            v[i].pop_back();
        }
//        cout << "v[" << i << "] = "; for (int y : v[i]) cout << y << ' ';
//        cout << "\n";
        mnew += v[i].size();
    }
    m = mnew;
    for (int src = 1; src <= n; ++src) {
        int res = init;
        int m1 = m;
        int i = src;
        multiset<int> s;
        vector<int> numdone(n+1, 0);
//        cout << "src = " << src << "\n";
        while (true) {
//            cout << "i = " << i << " ; clearing " << s.count(i) << "\n";
            m1 -= s.count(i);
            while (s.count(i)) {
                s.erase(i);
            }
            if (m1 == 0) {
                break;
            }
            ++res;
            if (numdone[i] < v[i].size()) {
                int idx = v[i].size() - numdone[i] - 1;
                s.insert(v[i][idx]);
//                cout << "adding " << v[i][idx] << " to set\n";
                ++numdone[i];
            }
            i = i == n ? 1 : i+1;
        }
//        cout << "result = ";
        cout << res << ' ';
//        cout << "\n\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
