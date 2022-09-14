// https://leetcode.com/contest/weekly-contest-206/problems/check-if-string-is-transformable-with-substring-sort-operations/

class Solution {
public:
    const static int A = 10;
    
    // pos[d] = [all positions of digit d in string s]
    // i.e. pos[d][i] = position of i-th occurence of digit d
    vector<int> pos[A];
    // pos_idx[d] = how many times we have seen d so far
    int pos_idx[A];
    
    bool isTransformable(string s, string t) {
        // initialize arrays
        for (int i = 0; i < A; ++i) {
            pos[i].clear();
            pos_idx[i] = 0;
        }
        // fill pos array
        int n = s.size();    
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            pos[d].push_back(i);
        }
        // 
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
