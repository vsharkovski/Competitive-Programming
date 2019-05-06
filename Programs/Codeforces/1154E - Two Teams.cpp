#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+2), pos(n+2), L(n+2), R(n+2), team(n+2, 0);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        pos[a] = i;
        L[i] = i-1;
        R[i] = i+1;
    }
    int curr_team = 1;
    for (int x = n; x >= 1; --x) {
        int i = pos[x];
        if (team[i] != 0) continue;
        team[i] = curr_team;
        L[R[i]] = L[i];
        R[L[i]] = R[i];
        int j_l = L[i];
        for (int cnt = 0; cnt < k && j_l >= 0; ++cnt) {
            team[j_l] = curr_team;
            j_l = L[j_l];
        }
        int j_r = R[i];
        for (int cnt = 0; cnt < k && j_r <= n; ++cnt) {
            team[j_r] = curr_team;
            j_r = R[j_r];
        }
        L[j_r] = j_l;
        R[j_l] = j_r;
        curr_team = curr_team == 1 ? 2 : 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << team[i];
    }
}
