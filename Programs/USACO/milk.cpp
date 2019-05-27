#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: milk
LANG: C++
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<pii> farmers(m);
    for (int i = 0; i < m; ++i) {
        cin >> farmers[i].first >> farmers[i].second;
    }

    sort(farmers.begin(), farmers.end());

    int cost = 0;

    for (auto& farmer : farmers) {
        int p = farmer.first, a = farmer.second;
        if (n > a) {
            cost += p*a;
            n -= a;
        } else {
            cost += p*n;
            n = 0;
            break;
        }
    }

    cout << cost << '\n';

}
