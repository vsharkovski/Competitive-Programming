#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int k;
    cin >> k;

    map<int, pair<int, int>> sums; //sum, seqi, xi

    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        int sum = 0;
        vector<int> v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
            sum += v[j];
        }
        for (int j = 0; j < n; ++j) {
            int sum1 = sum-v[j];
            auto it = sums.find(sum1);
            if (it == sums.end()) {
                sums[sum-v[j]] = {i+1, j+1};
            } else if (it->second.first != i+1) {
                cout << "YES\n";
                cout << it->second.first << " " << it->second.second << "\n"
                     << i+1 << " " << j+1 << endl;
                return 0;
            }

        }
    }
    cout << "NO\n";
}
