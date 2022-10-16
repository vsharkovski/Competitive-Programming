class Solution {
    const int inf = 1e9;

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = (int)jobDifficulty.size();
        vector<int> cur(n+1, inf), nxt(n+1, inf);
        cur[0] = 0;
        for (int day = 0; day < d; ++day) {
            for (int i = 0; i < n; ++i) {
                if (cur[i] == inf) continue;
                int max_this_day = 0;
                for (int k = i; k < n; ++k) {
                    max_this_day = max(max_this_day, jobDifficulty[k]);
                    nxt[k+1] = min(nxt[k+1], cur[i] + max_this_day);
                }
            }
            cur.swap(nxt);
            nxt.assign(n+1, inf);
        }
        int ans = cur[n];
        if (ans == inf) ans = -1;
        return ans;
    }
};
