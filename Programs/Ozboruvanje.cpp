#include <bits/stdc++.h>
using namespace std;
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
    int n, m;
    cin >> n >> m;
 
    vector<set<int>> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(set<int>{i+1});
    }
 
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        v[x].insert(v[y].begin(), v[y].end());
        v[y].insert(v[x].begin(), v[x].end());
    }
 
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].size() > mx) mx = v[i].size();
    }
    cout << mx-1 << endl;
}