#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie();

    int n;
    cin >> n;

    multiset<int> s;
    vector<int> taken;

    for (int i = 0; i < n*n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    while (taken.size() < n) {
        int x = *prev(s.end());
        s.erase(prev(s.end()));
//        cout << "x=" << x << endl;
        for (int y : taken) {
            int g = gcd(x, y);
//            cout << "    y=" << y << " g=" << g << endl;
            for (int i = 0; i < 2; ++i) {
                s.erase(s.find(g));
            }
        }
        taken.push_back(x);
    }

    for (int x : taken) {
        cout << x << ' ';
    }

}

