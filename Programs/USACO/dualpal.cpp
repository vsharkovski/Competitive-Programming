#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: dualpal
LANG: C++
*/

bool is_palindrome(int num, int base) {
    string str = "";
    while (num > 0) {
        str += char((num % base) + '0');
        num /= base;
    }
    for (int i = 0, j = str.length()-1; i < j; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    #endif

    int N, S;
    cin >> N >> S;

    while (N > 0) {
        ++S;
        int cnt = 0;
        for (int b = 2; b <= 10; ++b) {
            if (is_palindrome(S, b)) {
                ++cnt;
                if (cnt == 2) {
                    break;
                }
            }
        }
        if (cnt == 2) {
            cout << S << '\n';
            --N;
        }
    }

}
