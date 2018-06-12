#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> v(5, 0);
    cin >> v[0] >> v[1] >> v[2] >> v[3];

    int q[52][52];
    v[0]--; //for bottom
    v[3]--;
    memset(q, 3, sizeof(q));

    int choice = 0;
    int i = 0, j = 0;
    while (choice < 3) {
        while (v[choice] > 0) {
            q[i][j] = choice;
            j += 2;
            if (j >= 50) {
                j = 0;
                i += 2;
            }
            v[choice]--;
        }
        choice++;
    }

    i += 3;
    j = 0;
    for (int k = i-1; k < 51; ++k) {
        for (int l = 0; l < 51; ++l) {
            q[k][l] = 0;
        }
    }
    choice = 3;
    while (v[choice] > 0) {
        q[i][j] = choice;
        j += 2;
        if (j >= 50) {
            j = 0;
            i += 2;
        }
        v[choice]--;
    }

    cout << 50 << ' ' << 50 << '\n';
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            cout << char(q[i][j] + 'A');
        }
        cout << '\n';
    }

}
