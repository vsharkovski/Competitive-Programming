#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




const int mod = 1e9 + 7;

inline void add_self(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

inline void add_range(vector<int>& v, int x, int l, int r) {
    add_self(v[l], x);
    add_self(v[r+1], -x);
}

void Main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<int> curr(K+2, 0);
    curr[K] = 1;
    for (int i = 0; i < N; ++i) {
        // make difference array for easy range updates
        vector<int> diff(K+2, 0);
        add_range(diff, curr[0], 0, 0);
        for (int rem = 1; rem <= K; ++rem) {
            add_range(diff, curr[rem], rem - min(rem, a[i]), rem);
        }
        // make real array from difference array
        // this would be the "next" array, and i would set curr = next later,
        // but i can just set it directly
        curr[0] = diff[0];
        for (int rem = 1; rem <= K; ++rem) {
            curr[rem] = curr[rem-1];
            add_self(curr[rem], diff[rem]);
        }
    }
    // O(N*K^2)
//    for (int i = 0; i < N; ++i) {
//        vector<int> next(K+1, 0);
//        add_self(next[0], curr[0]);
//        for (int rem = 1; rem <= K; ++rem) {
//            for (int give = 0; give <= min(rem, a[i]); ++give) {
//                add_self(next[rem - give], curr[rem]);
//            }
//        }
//        curr = next;
//    }
    cout << curr[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
