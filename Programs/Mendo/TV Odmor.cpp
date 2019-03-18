#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const int MAXN = 55;

int N;
int startt[MAXN], endt[MAXN];

int dfs(int lastwatched, int endtime) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (endt[i] < endtime && startt[i] >= endt[lastwatched]) {
            res = max(res, endt[i] - startt[i] + dfs(i, endtime));
        }
    }
    return res;
}

void Main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        startt[i] = 60*h1 + m1;
        endt[i] = 60*h2 + m2;
        if (startt[i] >= endt[i]) endt[i] += 60*24;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, endt[i] - startt[i] + dfs(i, startt[i] + 1440));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
