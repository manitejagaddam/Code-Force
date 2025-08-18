#include<iostream>
#include<vector>


int main(){
    std::vector<std::vector<int>> mat(5, std::vector(5, 0));
    for(int row = 0 ; row < 5 ; row++){
        for(int col = 0 ; col < 5 ; col++){
            int temp;
            std::cin >> temp;
            if(temp){
                std::cout << std::abs(row - 2) + std::abs(col - 2);
                return 0;
            }
        }
    }

    std::cout << 0;
    return 0;

}