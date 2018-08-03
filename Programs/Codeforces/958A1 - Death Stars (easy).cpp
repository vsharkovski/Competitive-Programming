#include <bits/stdc++.h>
using namespace std;

int n;
bool A[3][12][12];

#define a A[0]
#define b A[1]
#define c A[2]

void rot90() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[j][n-i-1] = a[i][j];
        }
    }
    //
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = c[i][j];
        }
    }
    //cout << "\nrotated 90 degrees\n";
}

void flipv() {
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(a[i][j], a[n-i-1][j]);
        }
    }
    //cout << "\nflipped vertically\n";// print();
}

void fliph() {
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(a[i][j], a[i][n-j-1]);
        }
    }
    //cout << "\nflipped horizontally\n";// print();
}

bool check() {
    //print();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

bool fullcheck() {
    for (int i = 0; i < 4; ++i) {
        rot90();
        if (check()) { cout << "Yes"; return 1; }
    }
    return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    for (int q = 0; q < 2; ++q) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch;
                cin >> ch;
                A[q][i][j] = ch == 'X';
            }
        }
    }

    if (fullcheck()) return 0;

    flipv();
    if (fullcheck()) return 0;

    fliph();
    if (fullcheck()) return 0;

    flipv();
    if (fullcheck()) return 0;

    cout << "No";
}
