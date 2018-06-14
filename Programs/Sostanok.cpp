#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(n, 1);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second; // x, l
    }

    cnt[n-1] = 1;
    for (int i = n-2; i >= 0; --i) {
        int x = v[i].first, l = v[i].second;
        for (int j = i+1; j < n; ++j) {
            int x1 = v[j].first, l1 = v[j].second;
            if (x+l >= x1) {
                if (x1+l1 >= x+l) {
                    cnt[i] += cnt[j];
                    break;
                } else {
                    cnt[i]++;
                }
            } else {
                break;
            }
        }
    }

    for (int x : cnt) {
        cout << x << ' ';
    }



}
