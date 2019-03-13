#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int N;
    cin >> N;
    int S[305][305];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> S[i][j];
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (S[i][j] > S[i][k] + S[k][j]) {
                    cout << "GRESHKA\n";
                    return;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            bool ok = true;
            for (int k = 0; k < N; ++k) {
                if (S[i][j] == S[i][k] + S[k][j] && k != i && k != j) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += S[i][j];
            }
        }
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
