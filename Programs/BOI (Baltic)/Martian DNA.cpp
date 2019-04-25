#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int MAXN = 200005;
const int MAXK = 200005;

int N, K, R;
int D[MAXN];
int cnt[MAXN], want[MAXN];
int numneeded, numok;
int ans;

inline void add(int i) {
    ++cnt[i];
    if (cnt[i] == want[i]) {
        ++numok;
    }
}

inline void remove(int i) {
    if (cnt[i] == want[i]) {
        --numok;
    }
    --cnt[i];
}

inline bool canremove(int i) {
    return cnt[i] - 1 >= want[i];
}

inline bool valid() {
    return numok == numneeded;
}

int main() {
    cin >> N >> K >> R;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        cnt[i] = 0;
        want[i] = 0;
    }
    for (int i = 0; i < R; ++i) {
        int b, q;
        cin >> b >> q;
        want[b] = q;
    }
    ans = 1e9;
    numneeded = R;
    numok = 0;
    add(D[0]);
    if (valid()) {
        ans = 1;
    }
    int j = 0;
    for (int i = 1; i < N; ++i) {
        add(D[i]);
        while (j < i && canremove(D[j])) {
            remove(D[j]);
            ++j;
        }
        if (valid()) {
            ans = min(ans, i - j + 1);
        }
    }
    if (ans == 1e9) {
        cout << "impossible\n";
    } else {
        cout << ans << '\n';
    }
}
