#include <iostream>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    //pravime sekogas N da se gleda kako redovi, a M kako koloni (zamisli go kako rotiranje na cokoladoto za 90 stepeni)
    if (m > n) {
        int temp = n;
        n = m;
        m = temp;
    }
 
    int a = m;
 
    //A e maksimalnata golemina na stranata na kvadratot
    //ako A ne e paren, odzemame eden
    //kvadrat na neparen broj e sekogas neparen, no ni treba paren broj kocki, a kvadrat na paren broj e sekogas paren
    a = a % 2 != 0 ? a - 1 : a;
    int br = a * a;
 
    cout << br << endl;
}
