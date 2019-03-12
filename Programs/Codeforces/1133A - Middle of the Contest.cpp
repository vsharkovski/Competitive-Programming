#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;







int read() {
    char ch1, ch2;
    cin >> ch1 >> ch2;
    return 10*(ch1 - '0') + (ch2 - '0');
}

void Main() {
    char ch;
    int h1 = read();
    cin >> ch;
    int m1 = read();
    int h2 = read();
    cin >> ch;
    int m2 = read();
    int t1 = h1*60 + m1;
    int t2 = h2*60 + m2;
    int t3 = (t1 + t2) / 2;
    int h3 = t3 / 60;
    int m3 = t3 % 60;
    if (h3 < 10) cout << "0";
    cout << h3 << ":";
    if (m3 < 10) cout << "0";
    cout << m3 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
