#include <iostream>
#include <algorithm>
//#include <vector>
 
struct element {
    int value;
    int x_index;
};
 
bool sort_ascend(element i, element j) {
    return i.value < j.value;
}
 
bool sort_descend(element i, element j) {
    return i.value > j.value;
}
 
int main() {
    int n, k;
    std::cin >> n >> k;
 
    int x[n]; //knigi
    element xm[n]; //knigi, malo->golemo
    element xg[n]; //knigi, golemo->malo
 
    for (int i = 0; i < n; i++) {
        int z;
        std::cin >> z;
 
        x[i] = z;
 
        element e = {z, i};
        xm[i] = e;
        xg[i] = e;
    }
 
    std::sort(xm, xm + n, sort_ascend);
    std::sort(xg, xg + n, sort_descend);
 
    for (int i = k - 1; i >= 0; i--) {
        x[xm[i].x_index] = xg[i].value;
        x[xg[i].x_index] = xm[i].value;
        //std::cout << "zameniv " << xm[i].value << " so " << xg[i].value << std::endl;
    }
 
    for (int i = 0; i < n; i++) std::cout << x[i] << " ";
 
    return 0;
}
