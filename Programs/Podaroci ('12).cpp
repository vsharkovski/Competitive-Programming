#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, vk = 0, avg;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vk += x;
        v[i] = x;
    }

    if (vk % n > 0) {
        cout << "GRESHKA";
        return 0;
    }

    avg = vk/n;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > avg) {
            cnt += (v[i] - avg);
        } else if (v[i] < avg) {
            cnt += (avg - v[i]);
        }
    }

    cout << cnt/2;

}
