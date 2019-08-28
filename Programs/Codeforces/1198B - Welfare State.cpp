#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> bal(n);
    vector<int> last(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> bal[i];
    }
    int q;
    cin >> q;
    vector<int> maxq;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            bal[p] = x;
            last[p] = i;
            maxq.push_back(-1);
        } else {
            int x;
            cin >> x;
            maxq.push_back(x);
        }
    }
    maxq.push_back(-1);
    for (int i = (int)maxq.size() - 2; i >= 0; --i) {
        maxq[i] = max(maxq[i], maxq[i+1]);
    }
    for (int i = 0; i < n; ++i) {
        bal[i] = max(bal[i], maxq[last[i]+1]);
        cout << bal[i] << ' ';
    }
    cout << '\n';
}

