#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i += 7) {
        int j = n - i;
        if (j % 4 == 0) {
            cout << "DA\n";
            return;
        }
    }
    cout << "NE\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
