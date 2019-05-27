#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: transform
LANG: C++
*/

const int maxn = 10;

int n;
bool A[maxn][maxn];
bool B[maxn][maxn];
bool C[maxn][maxn];
bool D[maxn][maxn];

void print(bool Z[maxn][maxn]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << Z[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool okay() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (C[i][j] != A[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void reset() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = B[i][j];
        }
    }
}

void rot() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            D[j][n-i-1] = C[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = D[i][j];
        }
    }
}

void flip() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n/2; ++j) {
            swap(C[i][j], C[i][n-j-1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    #endif

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            A[i][j] = ch == '@';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            B[i][j] = ch == '@';
        }
    }

    reset();
    rot(); rot(); rot();
    if (okay()) {
        cout << 1 << endl;
        return 0;
    }

    reset();
    rot(); rot();
    if (okay()) {
        cout << 2 << endl;
        return 0;
    }

    reset();
    rot();
    if (okay()) {
        cout << 3 << endl;
        return 0;
    }

    reset();
    flip();
    if (okay()) {
        cout << 4 << endl;
        return 0;
    }

    for (int i = 1; i <= 3; ++i) {
        rot();
        if (okay()) {
            cout << 5 << endl;
            return 0;
        }
    }

    reset();
    if (okay()) {
        cout << 6 << endl;
        return 0;
    }

    cout << 7 << endl;
    return 0;

}
