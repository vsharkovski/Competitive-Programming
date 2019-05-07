#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
//#include <iostream>



class FirstWord
{
    public:
    int findFirstWord(vector<string> rules) {
//        vector<string> new_rules;
//        sort(rules.begin(), rules.end());
//        for (int i = 0; i < rules.size(); ++i) {
//            if (i == 0 || rules[i] != rules[i-1]) {
//                new_rules.push_back(rules[i]);
//            }
//        }
//        swap(rules, new_rules);
        int n = rules.size();
        int minlen = 1e9;
        vector<bool> taken(n);
        for (int first = 0; first < n; ++first) {
            taken.assign(n, false);
            taken[first] = true;
            char last = rules[first][1];
            int len = 2;
//            string _str = rules[first];
            while (true) {
                bool did_something = false;
                for (int i = 0; i < n; ++i) {
                    if (taken[i]) continue;
                    if (last == rules[i][0]) {
                        taken[i] = true;
                        last = rules[i][1];
                        len += 1;
                        did_something = true;
//                        _str += rules[i][1];
                        break;
                    } else if (last == rules[i][1]) {
                        taken[i] = true;
                        last = rules[i][0];
                        len += 1;
                        did_something = true;
//                        _str += rules[i][0];
                        break;
                    }
                }
                if (did_something) continue;
                for (int i = 0; i < n; ++i) {
                    if (taken[i]) continue;
                    taken[i] = true;
                    last = rules[i][1];
                    len += 2;
                    did_something = true;
//                    _str += rules[i];
                    break;
                }
                if (did_something) continue;
                break;
            }
//            if (len < minlen) {
//                cout << "new minimum length: " << len << endl;
//                cout << "result: " << _str << endl;
//            }
            minlen = min(len, minlen);
        }
        return minlen;
    }
};

//int main() {
//    FirstWord nut;
//    cout << nut.findFirstWord({"ab","bc","cd","de","ef","fg","gh","hi","ai"}) << endl;
//}
