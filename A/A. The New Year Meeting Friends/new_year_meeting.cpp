#include <iostream>


int main(){
    int x1, x2, x3;
    std::cin >> x1 >> x2 >> x3;
    // int avg = (x1 + x2 + x3) / 3;

    // std::cout << std::abs(x1 - avg) + std::abs(x2 - avg) + std::abs(x3 - avg);
    int min_num = x1;
    min_num = min_num > x2 ? x2 : min_num;
    min_num = min_num > x3 ? x3 : min_num;

    int max_num = x1;
    max_num = max_num < x2 ? x2 : max_num;
    max_num = max_num < x3 ? x3 : max_num;

    std::cout << max_num - min_num;

    return 0;
}