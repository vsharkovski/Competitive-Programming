#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: milk2
LANG: C++
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    #endif

    const int maxtime = 1000000;

    int n;
    cin >> n;

    int min_a = maxtime, max_b = 0;

    vector<int> incr(maxtime+1, 0), decr(maxtime+1, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        min_a = min(min_a, a);
        max_b = max(max_b, b);
        ++incr[a];
        ++decr[b];
    }

    int bal = 0;
    int max_streak = 0, streak = 0;
    int max_unmilk = 0, unmilk = 0;
    for (int t = min_a; t <= max_b; ++t) {
        bal += incr[t];
        if (bal > 0) {
            unmilk = 0;
            if (bal - decr[t] > 0) {
                ++streak;
            }
            max_streak = max(max_streak, streak);
        }
        bal -= decr[t];
        if (bal == 0) {
            streak = 0;
            if (t < max_b) {
                ++unmilk;
            }
            max_unmilk = max(max_unmilk, unmilk);
        }
    }


    cout << max_streak << ' ' << max_unmilk << '\n';

}
