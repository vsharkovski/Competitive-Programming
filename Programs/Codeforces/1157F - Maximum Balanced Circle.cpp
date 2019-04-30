#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int inf = 1e9;
const int maxa = 200002;

int n;
int cnt[maxa];
int cntsum[maxa];
int nxt[maxa]; // nxt[i] = j such that min(cnt[i], cnt[i+1], ..., cnt[j]) >= 2

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    for (int a = 1; a < maxa; ++a) {
        cntsum[a] = cntsum[a-1] + cnt[a];
    }
    for (int a = maxa-1; a >= 1; --a) {
        nxt[a] = -1;
        if (cnt[a] >= 2) {
            nxt[a] = max(a, nxt[a+1]);
        }
    }
    int bestx = 1, besty = 1, besttotal = 0;
    for (int x = 1; x < maxa; ++x) {
        if (cnt[x] == 0) {
            continue;
        }
        int y = nxt[x+1];
        if (y == -1) {
            y = x;
        }
        if (y+1 < maxa && cnt[y+1] >= 1) {
            y = y+1;
        }
        int total = cntsum[y] - cntsum[x-1];
        if (total > besttotal) {
            besttotal = total;
            bestx = x;
            besty = y;
        }
    }
    cout << besttotal << '\n';
    for (int a = bestx+1; a <= besty; ++a) {
        for (int i = 0; i < cnt[a]-1; ++i) {
            cout << a << ' ';
        }
    }
    for (int a = besty; a > bestx; --a) {
        cout << a << ' ';
    }
    for (int i = 0; i < cnt[bestx]; ++i) {
        cout << bestx << ' ';
    }
}
