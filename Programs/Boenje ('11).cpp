#include <bits/stdc++.h>
using namespace std;

int n, best_price = 1e9;
vector<vector<int>> v;

void f(int i, int prev_color, int curr_price, int first_color) {
    if (i == n) {
        if (prev_color != first_color && best_price > curr_price) {
            best_price = curr_price;
        }
        return;
    }
    for (int j = 0; j < 3; ++j) {
        if (j == prev_color) continue;
        f(i+1, j, curr_price + v[i][j], first_color);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    for (int j = 0; j < 3; ++j) {
        f(1, j, v[0][j], j);
    }

    cout << best_price;
}
