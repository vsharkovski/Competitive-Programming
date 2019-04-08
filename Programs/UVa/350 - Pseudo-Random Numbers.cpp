#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int Z, I, M, L;

int f(int x) {
    return (Z*x + I) % M;
}

pair<int, int> floyd(int x0) {
    // make k*length steps
    int a = f(x0), b = f(f(x0));
    while (a != b) a = f(a), b = f(f(b));
    // find first element in cycle
    a = x0;
    while (a != b) a = f(a), b = f(b);
    int first = a;
    // find length
    int length = 1;
    a = f(b);
    while (a != b) a = f(a), ++length;
    return pair<int, int>(first, length);
}

void Main() {
    int Case = 1;
    while (cin >> Z >> I >> M >> L, Z+I+M+L != 0) {
        cout << "Case " << Case++ << ": " << floyd(L).second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
