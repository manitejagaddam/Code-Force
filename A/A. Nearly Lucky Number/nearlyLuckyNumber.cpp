#include <iostream>


bool isNearlyLucky(long long num){
    int lucky_count = 0;
    while(num){
        int digit = num % 10;
        if(digit == 4 || digit == 7) lucky_count++;
        num /= 10;
    }
    // std::cout << lucky_count << " ";
    return lucky_count == 4 || lucky_count == 7;
}

int main(){
    long long num;
    std::cin >> num;
    // std::cout << num << " ";
    if(isNearlyLucky(num)) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}