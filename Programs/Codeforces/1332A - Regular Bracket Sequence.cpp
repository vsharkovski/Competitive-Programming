#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



void Main() {
    int cnt1, cnt2, cnt3, cnt4;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
    if (cnt1 != cnt4) {
        cout << 0;
        return;
    }
    if (cnt3 > 0 && (cnt1 == 0 || cnt4 == 0)) {
        cout << 0;
        return;
    }
    cout << 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
