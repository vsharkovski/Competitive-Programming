#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;







void Main() {
    int N;
    ll W;
    cin >> N >> W;
    vector<ll> weight(N);
    vector<int> value(N);
    int total_value = 0;
    for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
        total_value += value[i];
    }
    vector<ll> dp(total_value+1, 2e9);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int v = total_value; v >= value[i]; --v) {
            dp[v] = min(dp[v], dp[v - value[i]] + weight[i]);
        }
    }
    for (int v = total_value; v >= 0; --v) {
        if (dp[v] <= W) {
            cout << v << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
