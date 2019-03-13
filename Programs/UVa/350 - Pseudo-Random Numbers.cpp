#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





int Z, I, M, L;

int f(int x) {
    return (Z*x + I) % M;
}

pair<int, int> floyd(int x0) {
     int t = f(x0), h = f(f(x0));
     while (t != h) {
        t = f(t), h = f(f(h));
     }
     int start = 0;
     h = x0;
     while (t != h) {
        t = f(t), h = f(h);
        ++start;
     }
     int length = 1;
     h = f(t);
     while (t != h) {
        h = f(h);
        ++length;
     }
     return pair<int, int>(start, length);
}

void Main() {
    int Case = 1;
    while (cin >> Z >> I >> M >> L, Z != 0 || I != 0 || M != 0 || L != 0) {
        pair<int, int> ans = floyd(L);
        cout << "Case " << Case++ <<": " << ans.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
