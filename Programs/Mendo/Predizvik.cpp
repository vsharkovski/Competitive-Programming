#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 160;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool good(ll a, ll b) {
    if (gcd(a, b) != 1) return false;
    ll csq = a*a + b*b;
    ll c = floor(sqrt(csq));
    return c*c == csq;
}

int n;
int length[maxn];
vector<int> adj[maxn];

int match[maxn], visited[maxn];

int augmented_path(int l) {
    if (visited[l]) return 0;
    visited[l] = 1;
    for (int r : adj[l]) {
        if (match[r] == -1 || augmented_path(match[r])) {
            match[r] = l;
//            cout << "matched (" << l << ", " << r << ")\n";
            return 1;
        }
    }
    return 0;
}

void Main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> length[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (good(length[i], length[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    memset(match, -1, sizeof(match));
    int matches = 0;
    for (int l = 0; l < n; ++l) {
        memset(visited, 0, sizeof(visited));
        matches += augmented_path(l);
    }
    cout << matches << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
