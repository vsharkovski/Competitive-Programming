#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



inline int lsb(int x) {
    return x & -x;
}

int N;
vector<int> arr;
vector<int> ft;

void update(int k, int x) {
    int diff = x - arr[k];
    arr[k] = x;
    for (; k <= N; k += lsb(k)) {
        ft[k] += diff;
    }
}

int sum(int k) {
    int res = 0;
    for (; k >= 1; k -= lsb(k)) {
        res += ft[k];
    }
    return res;
}

int sum(int x, int y) {
    return sum(y) - sum(x-1);
}

void print() {
    cout << "ft (N=" << N << ") is now: ";
    for (int i = 1; i <= N; ++i) {
        cout << ft[i] << ' ';
    }
    cout << "\n";
}

void Main() {
    int Case = 1;
    while (cin >> N, N != 0) {
        arr.assign(N+1, 0);
        ft.assign(N+1, 0);
        for (int i = 1; i <= N; ++i) {
            int x;
            cin >> x;
            update(i, x);
        }
        if (Case > 1) cout << '\n';
        cout << "Case " << Case++ << ":\n";
        string action;
        while (cin >> action, action != "END") {
            if (action == "S") {
                int x, r;
                cin >> x >> r;
                update(x, r);
            } else { // M
                int x, y;
                cin >> x >> y;
                cout << sum(x, y) << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
