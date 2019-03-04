#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



void Main() {
    int n, z = 0, m = 0, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        z += x, m += y;
    }
    if (z > m) {
        cout << "zelka" << endl << z << endl;
    } else {
        cout << "morkov" << endl << m << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
