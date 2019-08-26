#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
const int maxk = 6;

int n, k, c;
int p[maxn][maxk];

struct State {
    int score, start;
    int best[maxk]; // indices of people in team
    bitset<maxn> forbidden; // indices already used

    State() {
        start = 0;
        calc_score();
    }
    State(State* pre, int new_start) {
        start = new_start;
        forbidden = pre->forbidden;
        forbidden[pre->best[start]] = true;
        for (int i = 0; i < start; ++i) {
            best[i] = pre->best[i];
        }
        calc_score();
    }
    void calc_score() {
        for (int j = start; j < k; ++j) {
            int besti = -1;
            for (int i = 0; i < n; ++i) {
                if (forbidden[i] || in_best(j, i)) {
                    continue;
                }
                if (besti == -1 || p[i][j] > p[besti][j]) {
                    besti = i;
                }
            }
            if (besti == -1) {
                score = -1e9;
                return;
            }
            best[j] = besti;
        }
        score = 0;
        for (int j = 0; j < k; ++j) {
            int res = 0;
            for (int i = 0; i < k; ++i) {
                res = max(res, p[best[i]][j]);
            }
            score += res;
        }
    }
    bool in_best(int end, int x) {
        for (int i = 0; i < end; ++i) {
            if (best[i] == x) {
                return true;
            }
        }
        return false;
    }
};

struct State_Compare {
    bool operator () (State* l, State* r) {
        return l->score < r->score;
    }
};

priority_queue<State*, vector<State*>, State_Compare> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> p[i][j];
        }
    }
    int ans = 0;
    pq.push(new State());
    State* top;
    while (c--) {
        top = pq.top();
        pq.pop();
        ans = top->score;
        for (int i = top->start; i < k; ++i) {
            pq.push(new State(top, i));
        }
    }
    cout << ans << endl;
}
