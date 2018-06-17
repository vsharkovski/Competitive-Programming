#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

struct S {
    int i;
    int c;
    int p;
    ll res;
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<S> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].p;
        v[i].i = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].c;
    }
    sort(v.begin(), v.end(), [](S &x, S &y){
        return x.p < y.p;
    });

    int i;
    multiset<int> s;
    ll ssum = 0;

    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            v[i].res = v[i].c;
        }
    } else {
        v[0].res = v[0].c;
        ssum += v[0].c;
        s.insert(v[0].c);
        for (i = 1; i < min(k, n); ++i) {
            ssum += v[i].c;
            s.insert(v[i].c);
            v[i].res = ssum;
        }
        if (k < n) {
            for (i = i; i < n; ++i) {
                v[i].res = ssum + v[i].c;
                auto bit = s.begin();
                if (v[i].c > *bit) {
                    ssum = ssum - (*bit) + v[i].c;
                    s.erase(bit);
                    s.insert(v[i].c);
                }
            }
        }
    }

    sort(v.begin(), v.end(), [](S &x, S &y){
        return x.i < y.i;
    });

    for (S s : v) {
        cout << s.res << ' ';
    }

}
