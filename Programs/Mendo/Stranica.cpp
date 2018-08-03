#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    bool broken[10];
    string ps;
    int p, n;

    cin >> ps >> n;
    p = stoi(ps);
    memset(broken, 0, sizeof(broken));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        broken[x] = 1;
    }

    auto isok = [broken](int q) {
        while (q > 0) {
            int d = q % 10;
            if (broken[d]) {
                return false;
            }
            q /= 10;
        }
        return true;
    };

    int best = 100;
    for (int q = p; q < 100000; ++q) {
        if (isok(q)) {
            if (abs(q-p) < abs(p-best)) {
                best = q;
            }
            break;
        }
    }
    for (int q = p; q >= 0; --q) {
        if (isok(q)) {
            if (abs(q-p) < abs(p-best)) {
                best = q;
            }
            break;
        }
    }

    if (best == 100) {
        cout << abs(p-best) << '\n';
    } else {
        cout << min( (int)(to_string(best).size() + abs(p-best)), abs(p-100) ) << '\n';
    }

}
