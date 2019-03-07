#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




int m, q;
int L[5005], R[5005];
int incr[5005];
int psum1[5005], psum2[5005];

inline int cnt1(int l, int r) {
    return psum1[r] - psum1[l-1];
}

inline int cnt2(int l, int r) {
    return psum2[r] - psum2[l-1];
}

void Main() {
    cin >> m >> q;
    for (int i = 0; i < q; ++i) {
        cin >> L[i] >> R[i];
        ++incr[L[i]];
        --incr[R[i]+1];
    }
    int total = 0;
    int curr = 0;
    for (int i = 1; i <= m; ++i) {
        curr += incr[i];
        psum1[i] = psum1[i-1];
        psum2[i] = psum2[i-1];
        if (curr == 1) {
            ++psum1[i];
            ++psum2[i];
        } else if (curr == 2) {
            ++psum2[i];
        }
        if (curr > 0) {
            ++total;
        }
    }
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        for (int j = i+1; j < q; ++j) {
            int l1 = L[i], r1 = R[i];
            int l2 = L[j], r2 = R[j];
            int l3 = max(l1, l2), r3 = min(r1, r2);
            if (l3 <= r3) {
                ans = max(ans, total - cnt1(min(l1, l2), l3-1) - cnt2(l3, r3) - cnt1(r3+1, max(r1, r2)));
            } else {
                ans = max(ans, total - cnt1(l1, r1) - cnt1(l2, r2));
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
