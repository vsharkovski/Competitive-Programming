#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 500;

int n;
int weights[maxn];
int prefsum[maxn];
bitset<maxn> visited[maxn];
vector<int> choices; // 0 = L, 1 = R

bool dfs(int l, int r) {
    if (visited[l][r]) return false;
    visited[l][r] = true;
    if (l == 0 && r == n-1) {
        return true;
    }
    int chungus = prefsum[r] - (l == 0 ? 0 : prefsum[l-1]);
    if (l > 0 && chungus > weights[l-1]) {
        if (dfs(l-1, r)) {
            choices.push_back(0);
            return true;
        }
    }
    if (r+1 < n && chungus > weights[r+1]) {
        if (dfs(l, r+1)) {
            choices.push_back(1);
            return true;
        }
    }
    return false;
}

bool getsequence(vector<int>& w, vector<pii>& seq, int i0) {
    n = w.size();
    choices.clear();
    for (int i = 0; i < n; ++i) {
        visited[i].reset();
        weights[i] = w[i];
        prefsum[i] = weights[i];
        if (i > 0) prefsum[i] += prefsum[i-1];
    }
    for (int i = 0; i < n; ++i) {
        if (dfs(i, i)) {
            for (int idx = choices.size()-1; idx >= 0; --idx) {
                int c = choices[idx];
                seq.emplace_back(i0 + i, c);
                if (c == 0) {
                    --i;
                }
            }
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    vector<pii> seq;
    int sa = 0, sb = 0;
    int i = 0, j = 0;
    while (i < n && j < k) {
        vector<int> weights;
        sa = 0, sb = b[j];
        while (i < n && sa < sb) {
            weights.push_back(a[i]);
            sa += a[i];
            ++i;
        }
        if (sa != sb) {
            cout << "NO\n";
            return 0;
        }
        if (getsequence(weights, seq, j) == false) {
            cout << "NO\n";
            return 0;
        }
        ++j;
    }
    if (i < n || j < k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto& p : seq) {
        cout << p.first+1 << ' ' << (p.second ? 'R' : 'L') << '\n';
    }
}
