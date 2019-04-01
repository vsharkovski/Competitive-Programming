#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





void Main() {
    int n;
    cin >> n;
    vector<int> isbad(n+1, 0);
    vector<int> numgood(n+1, 0), numbad(n+1, 0);
    vector<int> parent(n+1);
    for (int i = 1; i <= n; ++i) {
        int p, c;
        cin >> p >> c;
        parent[i] = p;
        isbad[i] = c;
        if (p != -1) {
            if (c) {
                ++numbad[p];
            } else {
                ++numgood[p];
            }
        }
    }
    vector<int> order;
    for (int u = 1; u <= n; ++u) {
        if (isbad[u] == 0 || numgood[u] > 0) continue;
        // delete it
        order.push_back(u);
        int p = parent[u];
        --numbad[p]; // because removing u
        numbad[p] += numbad[u];
        numgood[p] += numgood[u];
    }
    if (order.empty()) {
        cout << "-1\n";
    } else {
        for (int x : order) {
            cout << x << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
