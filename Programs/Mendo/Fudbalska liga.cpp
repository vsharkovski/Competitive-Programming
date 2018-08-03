#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int C = 6*N - 6 - K;
    int vk = 2*N - 2;

    int bn, bz = 100000000;

    for (int n = 0; n <= vk; ++n) {
        for (int z = 0; z <= vk-n; ++z) {
            if (2*n + 3*z == C && z < bz) {
                bn = n;
                bz = z;
            }
        }
    }

    cout << vk-bn-bz << ' ' << bn << ' ' << bz << '\n';

}
