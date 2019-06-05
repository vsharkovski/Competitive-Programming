#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: ariprog
*/

const int maxnum = 250*250*2;

int n, m;
bool isbisquare[maxnum + 10];
vector<int> bisquares;
vector<pii> progressions;

int main() {
    #ifndef _DEBUG
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;

    for (int p = 0; p <= m; ++p) {
        for (int q = p; q <= m; ++q) {
            int x = p*p + q*q;
            if (isbisquare[x] == false) {
                bisquares.push_back(x);
                isbisquare[x] = true;
            }
        }
    }

    sort(bisquares.begin(), bisquares.end());

//    cout << "bisquares: ";
//    for (int x : bisquares) {
//        cout << x << ' ';
//    }
//    cout << '\n';

    for (int i = 0; i < (int)bisquares.size(); ++i) {
        for (int j = i+1; j < (int)bisquares.size(); ++j) {
            int a = bisquares[i], b = bisquares[j] - bisquares[i];
            int sz = 0;
            for (int x = a; x <= maxnum && sz < n; x += b) {
                if (isbisquare[x] == false) {
                   break;
                }
                ++sz;
            }
            if (sz == n) {
                progressions.emplace_back(a, b);
            }
        }
    }

    sort(progressions.begin(), progressions.end(), [&] (pii& x, pii& y) {
        return (x.second != y.second) ? (x.second < y.second) : (x.first < y.first);
    });

    if (progressions.empty()) {
        cout << "NONE\n";
    } else {
        for (auto& p : progressions) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }


}
