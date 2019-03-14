#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



inline long long pow10(int p) {
    long long res = 1;
    while (p > 0) {
        res *= 10;
        --p;
    }
    return res;
}

void Main() {

    long long _n;
    int k;
    cin >> _n >> k;

    // zabelezi deka brojot od inputot go zgolemuvame za 1
    // ova olesnuva mnogu raboti bidejki se bara najmaliot <pogolem> broj
    string n = to_string(_n + 1);

    // polesno se raboti ako n e reverse-nat
    reverse(n.begin(), n.end());

    // gi broime sedumkite
    int num7 = 0;
    for (char ch : n) {
        if (ch == '7') {
            ++num7;
        }
    }

    // zabelezi deka n e reverse-nat (najmalata cifra e za
    // edinici, slednata za desetki, i taka natamu)
    int i = 0;

    while (num7 < k && i < n.length()) {
        //cout << "n: " << n << " ; num7: " << num7 << '\n';
        if (n[i] < '7') {
            n[i] = '7';
            ++num7;
            for (int j = 0; j < i; ++j) {
                if (n[j] != '7') {
                    if (num7 < k) {
                        n[j] = '7'; // bidejki treba da dodademe uste sedumki
                        ++num7;
                    } else {
                        n[j] = '0'; // bidejki go barame najmaliot pogolem broj
                    }
                }
            }
            ++i;
        } else if (n[i] > '7') {
            reverse(n.begin(), n.end());
            // stoll pretvoruva string vo long long
            // vsusnost sledniov red ja zgolemuva cifrata na i-tata pozicija za 1
            // go pravam vaka vo slucaj n[i] da e 9, pa neli treba i slednite
            // cifri da se smenat i slicno... vaka e polesno
            _n = stoll(n) + pow10(i);
            n = to_string(_n);
            reverse(n.begin(), n.end());
            // sega bidejki se smenija tolku raboti, pocnuvame od novo
            num7 = 0;
            for (char ch : n) {
                if (ch == '7') {
                    ++num7;
                }
            }
            i = 0;
        } else {
            ++i;
        }
    }

    while (num7 < k) {
        // sme stignale do krajot na n
        n += '7';
        ++num7;
    }

    reverse(n.begin(), n.end());

    cout << n << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
