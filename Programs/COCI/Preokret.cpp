#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int A, B;
    bool As[3000] = {}, Bs[3000] = {};
 
    cin >> A;
    for (int i = 0; i < A; ++i) {
        int s;
        cin >> s;
        As[s] = true;
    }
    cin >> B;
    for (int i = 0; i < B; ++i) {
        int s;
        cin >> s;
        Bs[s] = true;
    }
 
    int ans1 = 0, ans2 = 0;
    int Ascore = 0, Bscore = 0;
    bool af = false, bf = false;
 
    for (int s = 1; s <= 4*12*60; ++s) {
        if (As[s]) {
            ++Ascore;
            if (s <= 2*12*60) {
                ++ans1;
            }
        }
        if (Bs[s]) {
            ++Bscore;
            if (s <= 2*12*60) {
                ++ans1;
            }
        }
        if (!af && !bf) {
            if (Ascore > Bscore) {
                bf = true;
            } else {
                af = true;
            }
        }
        if (af && Ascore > Bscore) {
            ++ans2;
            af = false;
            bf = true;
        }
        if (bf && Ascore < Bscore) {
            ++ans2;
            af = true;
            bf = false;
        }
    }
 
    cout << ans1 << '\n' << ans2;
}
