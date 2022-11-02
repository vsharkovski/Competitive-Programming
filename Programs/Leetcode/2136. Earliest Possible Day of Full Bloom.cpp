/*
if starting to plant seed, don't stop until it's planted

plants with smallest gT should be planted last?
plants with biggest gT should be planted first?
*/

class Solution {
    typedef pair<int, int> pii;
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        size_t n = plantTime.size();
        vector<pii> plants(n);
        for (size_t i = 0; i < n; ++i) {
            plants[i].first = plantTime[i];
            plants[i].second = growTime[i];
        }
        sort(plants.begin(), plants.end(), [&](const pii& a, const pii& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        int t = 0, maxEnd = 0;
        for (size_t i = 0; i < n; ++i) {
            t += plants[i].first;
            maxEnd = max(maxEnd, t + plants[i].second);
        }
        return maxEnd;
    }
};
