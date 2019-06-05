#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: sprime
*/

bool is_prime(int x) {
    if (x % 2 == 0) return false;
    for (int y = 3; y*y <= x; y += 2) {
        if (x % y == 0) return false;
    }
    return true;
}

int main() {
    #ifndef _DEBUG
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<int> ok_digits = {1, 3, 7, 9};

    vector<int> a = {2, 3, 5, 7};
    vector<int> b;

    --n;
    while (n > 0) {
        --n;
        while (!a.empty()) {
            int x = a.back();
            a.pop_back();
            for (int d : ok_digits) {
                int y = 10*x + d;
                if (is_prime(y)) {
                    b.push_back(y);
                }
            }
        }
        swap(a, b);
    }

    sort(a.begin(), a.end());
    for (int x : a) {
        cout << x << '\n';
    }

}
