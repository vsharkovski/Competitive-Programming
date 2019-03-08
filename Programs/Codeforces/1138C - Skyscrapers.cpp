#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





int R, C;
int grid[1005][1005];
int rowsetsize[1005];
int colsetsize[1005];
int rowdata[1005][1005];
int coldata[1005][1005];

void Main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> grid[r][c];
        }
    }
    for (int r = 0; r < R; ++r) {
        set<int> data;
        map<int, int> id;
        for (int c = 0; c < C; ++c) {
            data.insert(grid[r][c]);
        }
        rowsetsize[r] = data.size();
        int i = 0;
        for (int x : data) {
            id[x] = i;
            ++i;
        }
        for (int c = 0; c < C; ++c) {
            rowdata[r][c] = id[grid[r][c]] + 1;
        }
    }
    for (int c = 0; c < C; ++c) {
        set<int> data;
        map<int, int> id;
        for (int r = 0; r < R; ++r) {
            data.insert(grid[r][c]);
        }
        colsetsize[c] = data.size();
        int i = 0;
        for (int x : data) {
            id[x] = i;
            ++i;
        }
        for (int r = 0; r < R; ++r) {
            coldata[r][c] = id[grid[r][c]] + 1;
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int rsz = rowsetsize[r], csz = colsetsize[c];
            if (rowdata[r][c] > coldata[r][c]) {
                csz += rowdata[r][c] - coldata[r][c];
            } else if (rowdata[r][c] < coldata[r][c]) {
                rsz += coldata[r][c] - rowdata[r][c];
            } else {

            }
            cout << max(rsz, csz) << ' ';
        }
        cout << '\n';
    }
    return;
/*
4 5
10 20 10 5 14
13 10 20 11 20
11 13 14 15 16
14 5 10 14 20
*/
    cout << "\ngrid:\n";
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cout << grid[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";
    cout << "rowdata:\n";
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cout << rowdata[r][c] << ' ';
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "coldata:\n";
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cout << coldata[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
