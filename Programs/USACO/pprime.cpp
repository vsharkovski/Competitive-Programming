#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: pprime
*/

const int maxnum = 100000000;
const int maxn = 9;

int pow10[maxn];

int a, b;
vector<int> pprimes;

bool is_prime(int x) {
    if (x % 2 == 0) return false;
    for (int y = 3; y*y <= x; y += 2) {
        if (x % y == 0) return false;
    }
    return true;
}

void dfs(int n, int i, int j, int x) {
    if (i > j) {
        if (is_prime(x)) {
            pprimes.push_back(x);
        }
    } else {
        for (int d = (i == 0); d <= 9; ++d) {
            int y = x + pow10[i]*d;
            if (i < j) {
                y += pow10[j]*d;
            }
            dfs(n, i+1, j-1, y);
        }
    }
}


int main() {
    #ifndef _DEBUG
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    pow10[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pow10[i] = pow10[i-1] * 10;
    }

    cin >> a >> b;

    for (int n = 0; n < maxn; ++n) {
        dfs(n, 0, n-1, 0);
    }

    for (int p : pprimes) {
        if (p >= a && p <= b) {
            cout << p << '\n';
        }
    }

}
