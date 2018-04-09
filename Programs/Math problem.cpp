#include <bits/stdc++.h>
using namespace std;
 
const int M = 1000007;
 
int main() {
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
    vector<int> prime[101];
    for (int i = 2; i <= 100; ++i) {
        int n = i;
        while (n % 2 == 0) {
            prime[i].push_back(2);
            n /= 2;
        }
        for (int j = 3; j <= 100; j += 2) {
            while (n % j == 0) {
                prime[i].push_back(j);
                n /= j;
            }
        }
    }
 
    int T;
    cin >> T;
 
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        int f[101] = {};
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            for (int k = 0; k < prime[x].size(); ++k) {
                ++f[prime[x][k]];
            }
        }
        int A = 1;
        for (int j = 2; j < 101; ++j) {
            if (f[j] % 2 == 1) {
                A = (A * j) % M;
            }
        }
        cout << A << endl;
    }
}