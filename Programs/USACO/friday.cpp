#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: friday
LANG: C++
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n;
    cin >> n;

    int sz[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int cnt[8] = {};

    int year = 1900, month = 1, day = 1, weekday = 1;

    while (year <= 1900+n-1) {
        if (day == 13) {
            ++cnt[weekday];
        }
        ++day;
        weekday = weekday < 7 ? weekday+1 : 1;
        if (day > sz[month]) {
            if (month != 2) {
                ++month;
                day = 1;
                if (month > 12) {
                    month = 1;
                    ++year;
                }
            } else {
                // February
                if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                    // leap year
                    if (day > 29) {
                        ++month;
                        day = 1;
                    }
                } else {
                    // not leap year
                    ++month;
                    day = 1;
                }
            }
        }
    }

    vector<int> seq = {6, 7, 1, 2, 3, 4, 5};
    for (int weekday : seq) {
        cout << cnt[weekday];
        if (weekday != seq.back()) {
            cout << ' ';
        }
    }
    cout << '\n';

}
