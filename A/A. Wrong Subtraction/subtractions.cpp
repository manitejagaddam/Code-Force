#include <iostream>


int main(){
    int num, k;
    std::cin >> num >> k;

    for(int i = 0 ; i < k ; i++){
        int digit = num % 10;
        if(digit) num--;
        else num /= 10;
    }

    std::cout << num;

    return 0;
}