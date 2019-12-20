#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#include <iostream>

const double EPS = 1e-6;

class SolarDrone
{
  public:
    double ToDouble(string s) {
        double res = 0;
        double cnt = 1;
        bool founddot = false;
        for (char& ch : s) {
            if (ch == '.') {
                founddot = true;
            } else {
                if (founddot) {
                    cnt *= 10;
                }
                res = (10 * res) + double(ch - '0');
            }
        }
        res /= cnt;
        return res;
    }
    string ToString(double a) {
        stringstream ss;
        ss << fixed;
        ss.precision(2);
        ss << a;
        return ss.str();
    }
    int n;
    double p1, p2;
    vector<double> x, h, t;
    bool possible(double m) {
        /*
        tan(t) * (h-m)
        */
        vector<pair<double, double>> intervals;
        for (int i = 0; i < n; ++i) {
            if (m <= h[i]) {
                double l = tan(t[i]) * (h[i] - m);
                intervals.emplace_back(x[i] - l, x[i] + l);
            }
        }
        sort(intervals.begin(), intervals.end());
        double L = -1, R = -1;
        for (auto& p : intervals) {
            double l = p.first, r = p.second;
            if (R < l) {
                L = l;
                R = r;
            } else {
                R = max(R, r);
            }
            if (L <= p1 && p1 <= R && L <= p2 && p2 <= R) {
                return true;
            }
        }
        return false;
    }
    string findMaxHeight(int L, int R, vector<string> x_coords, vector<string> heights, vector<string> tstr)
    {
        n = x_coords.size();
        p1 = L;
        p2 = R;
        x.resize(n);
        h.resize(n);
        t.resize(n);
        double maxh = 0;
        for (int i = 0; i < n; ++i) {
            x[i] = ToDouble(x_coords[i]);
            h[i] = ToDouble(heights[i]);
            t[i] = ToDouble(tstr[i]);
            maxh = max(maxh, h[i]);
        }
        double lo = 0, hi = maxh, mid, ans = -1;
        while (hi - lo > EPS) {
            mid = (lo + hi) / 2;
            if (possible(mid)) {
                ans = mid;
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (ans == -1) {
            return "Impossible";
        } else {
            return ToString(ans);
        }
    }
};

//
//int main() {
//    SolarDrone a;
//    cout << a.findMaxHeight(99, 198, {"111.38","136.12","160.88","185.62"}, {"10.46","12.04","18.38","14.55"}, {"0.85","0.93","0.72","0.96"}) << endl;
//    cout << a.findMaxHeight(90, 106, {"92.67","98.00","103.33"}, {"9.72","16.04","16.10"}, {"0.39","0.24","0.24"}) << endl;
//}
