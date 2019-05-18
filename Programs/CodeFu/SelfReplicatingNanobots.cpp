#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
//#include <iostream>


class SelfReplicatingNanobots
{
    public:
    int val[256];
    char lav[256];
    char merge(char a, char b) {
        int sum = val[a] + val[b];
        while (sum > 26) sum -= 26;
        return lav[sum];
    }
    string lastNanobot(string nanoBots)
    {
        int A = 1;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            val[ch] = A;
            lav[A] = ch;
            ++A;
        }
        string a = nanoBots, b = "";
        while (a.size() > 1) {
            for (int i = 0; i+1 < a.size(); ++i) {
                b += merge(a[i], a[i+1]);
            }
            swap(a, b);
            b = "";
        }
        return a;
    }
};

//
//int main() {
//    SelfReplicatingNanobots a;
//    cout << a.lastNanobot("aaaaaa");
//}
