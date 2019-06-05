#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
LANG: C++
TASK: holstein
*/



int main() {
    #ifndef _DEBUG
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    const int maxV = 25;
    const int maxG = 15;

    int V, G;
    int minreq[maxV];
    int gains[maxG][maxV];

    cin >> V;
    for (int i = 0; i < V; ++i) {
        cin >> minreq[i];
    }
    cin >> G;
    for (int i = 0; i < G; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> gains[i][j];
        }
    }

    int minnum = 1000, bestmask;
    int cnt[maxV];

    for (int m = 0; m < (1 << G); ++m) {
        for (int j = 0; j < V; ++j) {
            cnt[j] = 0;
        }
        int numscoops = 0;
        for (int i = 0; i < G; ++i) {
            if (m & (1 << i)) {
                ++numscoops;
                for (int j = 0; j < V; ++j) {
                    cnt[j] += gains[i][j];
                }
            }
        }
        bool satisfied = true;
        for (int j = 0; j < V; ++j) {
            if (cnt[j] < minreq[j]) {
                satisfied = false;
                break;
            }
        }
        if (satisfied && numscoops < minnum) {
            minnum = numscoops;
            bestmask = m;
        }
    }

    cout << minnum;
    for (int i = 0; i < G; ++i) {
        if (bestmask & (1 << i)) {
            cout << ' ' << i+1;
        }
    }
    cout << '\n';

}
