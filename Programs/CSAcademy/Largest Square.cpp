#include <bits/stdc++.h>
using namespace std;

int largestSquare(const vector<vector<int>>& A) {
    int N = A.size();
    int ans = 1;
    vector<vector<int>> dp(N, vector<int>(N, 1));
    for (int r = 1; r < N; ++r) {
        for (int c = 1; c < N; ++c) {
            if (A[r][c] == A[r-1][c-1] && A[r][c] == A[r][c-1] && A[r][c] == A[r-1][c]) {
                dp[r][c] = max(2, min({dp[r-1][c], dp[r][c-1], dp[r-1][c-1]}) + 1);
                ans = max(ans, dp[r][c]);
            }
        }
    }
    /*
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cout << dp[r][c] << ' ';
        }
        cout << '\n';
    }
    */
    return ans;
}
   
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A;
    for (int i = 0; i < N; ++i) {
        vector<int> row;
        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            row.push_back(val);
        }
        A.push_back(row);
    }
    
    cout << largestSquare(A) << "\n";
    return 0;
}
