class Solution {
public:
    const static int inf = 1e9;
    const static int A = 10;
    
    vector<int> pos[A];
    int pos_idx[A];
    
    bool isTransformable(string s, string t) {
        for (int i = 0; i < A; ++i) {
            pos[i].clear();
            pos_idx[i] = 0;
        }
        int n = s.size();    
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            pos[d].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            int d = t[i] - '0';
            if (pos_idx[d] == (int)pos[d].size()) {
                return false;
            }
            int j = pos[d][pos_idx[d]];
            for (int c = 0; c < d; ++c) {
                if (pos_idx[c] < (int)pos[c].size() && pos[c][pos_idx[c]] < j) {
                    return false;
                }
            }
            pos_idx[d]++;
        }
        return true;
    }
};
