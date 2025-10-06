#include <iostream>



int solve(){
    int num;
    std::cin >> num;

    return num % 3 == 0 ? 0 : 3 - num % 3;
}

int main(){
    int no_test_cases;
    std::cin >> no_test_cases;

    while(no_test_cases--){
        std::cout << solve() << std::endl;
    }

    return 0;
}