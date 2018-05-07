#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        vector<long long> b;
//        for (int j = 0; j < n; ++j) {
//            b[j] = a[j];
//        }
        bool success = 0;
        long long t = a[i];
        b.push_back(t);
        while (1) {
            if (t % 3 == 0 && binary_search(a.begin(), a.end(), t / 3)) {
                t /= 3;
            } else if (binary_search(a.begin(), a.end(), t*2)) {
                t *= 2;
            } else {
                break;
            }
            b.push_back(t);
            if (b.size() == n) {
                success = 1;
                break;
            }
        }

        if (success) {
            for (long long z : b)
                cout << z << ' ';
            break;
        }
    }
}
