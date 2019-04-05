#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




int n;

bool possible(int r1, int c1, int r2, int c2) {
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << "\n";
    cout.flush();
    string ans;
    cin >> ans;
    return ans == "YES";
}

void Main() {
    cin >> n;
    string moves1 = "", moves2 = "";
    int r = 1, c = 1;
    while (r + c != n + 1) {
        if (possible(r+1, c, n, n)) {
            ++r;
            moves1 += 'D';
        } else {
            ++c;
            moves1 += 'R';
        }
    }
    r = n, c = n;
    while (r + c != n + 1) {
        if (possible(1, 1, r, c-1)) {
            --c;
            moves2 += 'R';
        } else {
            --r;
            moves2 += 'D';
        }
    }
    reverse(moves2.begin(), moves2.end());
    cout << "! " << moves1 << moves2 << "\n";
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    #ifndef _DEBUG
    #endif
    Main();
}
