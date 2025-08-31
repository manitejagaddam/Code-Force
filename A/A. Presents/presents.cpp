#include <iostream>
#include <vector>


int main(){
    int len;
    std::cin >> len;
    std::vector<int> nums(len);
    for(int i = 0 ; i < len ; i++) std::cin >> nums[i];

    std::vector<int> presents(len);
    for(int i = 0 ; i < len ; i++){
        presents[nums[i] - 1] = i + 1;
    }
    
    for(int i : presents) std::cout << i << " ";

    return 0;
}