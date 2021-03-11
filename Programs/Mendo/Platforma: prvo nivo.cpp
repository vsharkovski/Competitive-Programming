#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool can_add(int L, int R, int a, int b) {
    int intr1 = max(L, a);
    int intr2 = min(R, b);
    //cout<<"-- ["<<L<<","<<R<<"]; ["<<a<<","<<b<<"]; ["<<intr1<<","<<intr2<<"]\n";
    if (L <= a && b <= R) {
        //cout<<"-- fully inside\n";
        return true;
    }
    if (a < L && R < b) {
        //cout <<"-- fully outside\n";
        return false;
    }
    if (intr1 > intr2) {
        //cout<<"-- no intersection\n";
        return false;
    }
    int intersection = intr2 - intr1;
    int outside = b - a - intersection;
    if (2*outside > b-a) {
        return false;
    }
    //cout<<"-- intr="<<intersection<<" outside="<<outside<<"\n";
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int L, R;
    cin >> n >> R;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i) {
        cin >> va[i] >> vb[i];
    }
    L = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int &a = va[j], &b = vb[j];
            if (a > -2000 && can_add(L, R, a, b)) {
                ++ans;
                L = min(L, a);
                R = max(R, b);
                //cout << "using ["<<a<<","<<b<<"], now big=["<<L<<","<<R<<"]\n";
                a = -2000;
            }
        }
    }
    cout << ans << '\n';
}
