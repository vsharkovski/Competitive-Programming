#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<vector<int>> k;
    int ax, ay;
    for (int y = 0; y < n; ++y) {
        vector<int> v;
        for (int x = 0; x < n; ++x) {
            int b; cin >> b;
            if (b == -1) {
                ax = x; ay = y;
            }
            v.push_back(b);
        }
        k.push_back(v);
    }
    int sum = 0;
    for (int y = 0; y < n; ++y) {
        if (y == ay) {
            continue;
        }
        for (int x = 0; x < n; ++x) {
            sum += k[y][x];
        }
        break;
    }
    int sum_m_a = 0;
    for (int x = 0; x < n; ++x) {
        sum_m_a += k[ay][x];
    }
    sum_m_a++; //a=-1
    int a = sum-sum_m_a;
    cout << a << endl;
}