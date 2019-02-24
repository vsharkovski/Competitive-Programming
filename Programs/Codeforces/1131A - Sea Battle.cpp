#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





void Main() {

    ll w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    cout << 4 + h1 + h2 + w2 + h2 + abs(w1 - w2) + h1 + w1 << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
