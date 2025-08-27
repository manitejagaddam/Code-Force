#include <iostream>



int main(){
    int len;
    std::cin >> len;
    for(int i = 0 ; i < len ; i++){
        int num;
        std::cin >> num;
        if(num) {
            std::cout << "HARD";
            return 0;
        }
    }

    std::cout << "EASY";
    return 0;
}