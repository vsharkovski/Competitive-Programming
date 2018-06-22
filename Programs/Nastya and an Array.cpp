#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != 0)
            s.insert(x);
    }
    cout << s.size();


}
