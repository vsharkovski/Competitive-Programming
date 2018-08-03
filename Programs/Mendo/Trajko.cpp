#include <iostream>
#include <string>
 
int main() {
    std::string niza;
    std::cin >> niza;
 
    long long int pari = 1;
 
    std::string pd = "duplo", pt = "troduplo", pm = "minus";
    std::string td = "", tt = "", tm = "";
 
    for (unsigned int i = 0; i < niza.length(); i++) {
        char x = tolower(niza[i]);
 
        if ((tt + x) == pt.substr(0, tt.length() + 1)) {
            tt += x;
 
            if (pt == tt) {
                pari *= 3;
                tt = "";
            }
 
        } else {
            tt = "";
 
            if ((td + x) == pd.substr(0, td.length() + 1)) {
                td += x;
 
                if (pd == td) {
                    pari *= 2;
                    td = "";
                }
 
            } else {
                td = "";
 
                if ((tm + x) == pm.substr(0, tm.length() + 1)) {
                    tm += x;
 
                    if (pm == tm) {
                        pari--;
                        tm = "";
                    }
 
                } else {
                    tm = "";
                }
            }
        }
 
 
    }
 
    std::cout << pari << std::endl;
 
    return 0;
}
