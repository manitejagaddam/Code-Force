#include <iostream>

int main(){
    int k, n, w;
    std::cin >> k >> n >> w;
    int req_amount = 0;
    for(int i = 1 ; i <= w ; i++){
        req_amount += (k * i);
    }
    int total_amount = req_amount - n;
    if(total_amount > 0) std::cout << total_amount;
    else std::cout << 0;

    return 0;
}