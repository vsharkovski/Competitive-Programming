#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    int arr[100] = {0};
    arr[0] = 1;
    int high = 0;
    for (int i = 0; i <= n; ++i) {
        int leftover = 0;
        for (int j = 0; j < 100; ++j) {
            arr[j] *= 2;
            arr[j] += leftover;
            leftover = 0;
            if (arr[j] > 9) {
                arr[j] -= 10;
                leftover = 1;
                if (j+1 > high) high = j+1;
            }
            //cout << arr[j];
        }
        //cout << endl;
    }
    arr[0] -= 2;
    for (int i = high; i >= 0; --i) cout << arr[i];
}
