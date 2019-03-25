#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
 
 
 
int A, B, C;
int N;
vector<int> arr;
vector<int> numempty;
 
bitset<10001> dp[3][10001];
vector<int> result;
 
int dfs(int i, int bp, int pr) {
    if (dp[pr][i][bp]) {
        return 0;
    }
    dp[pr][i][bp] = 1;
    if (i == N) {
        return 1;
    }
    if (arr[i] != -1) {
        if (i == 0 || arr[i] != arr[i-1]) {
            if (dfs(i+1, bp, arr[i])) {
                result.push_back(arr[i]);
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    int cp = numempty[i] - bp;
    if (bp < B && (i == 0 || pr != 1)) {
        if (dfs(i+1, bp+1, 1)) {
            result.push_back(1);
            return 1;
        }
    }
    if (cp < C && (i == 0 || pr != 2)) {
        if (dfs(i+1, bp, 2)) {
            result.push_back(2);
            return 1;
        }
    }
    return 0;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> A >> B >> C;
    N = A + B + C;
    arr.assign(N, -1);
    for (int i = 0; i < A; ++i) {
        int x;
        cin >> x;
        --x;
        arr[x] = 0;
    }
    numempty.assign(N, 0);
    numempty[0] = 0;
    for (int i = 1; i < N; ++i) {
        if (arr[i-1] == -1) {
            ++numempty[i];
        }
        numempty[i] += numempty[i-1];
    }
    int res = dfs(0, 0, 0);
    if (res == 0) {
        cout << -1;
    } else {
        reverse(result.begin(), result.end());
        for (int x : result) {
            cout << char(x+'A');
        }
    }
}
