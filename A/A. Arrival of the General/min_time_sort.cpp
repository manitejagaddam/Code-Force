#include <iostream>
#include <vector>



int findMinIdx(std::vector<int> & nums){
    int minNumber = INT_MAX;
    int minIdx = 0;
    int len = nums.size();
    for(int idx = 0 ; idx < len ; idx++){
        if(minNumber >= nums[idx]){
            minNumber = nums[idx];
            minIdx = idx;
        }
    }
    return minIdx;
}

int findMaxIdx(std::vector<int> & nums){
    int maxNumber = INT_MIN;
    int maxIdx = 0;
    int len = nums.size();
    for(int idx = 0 ; idx < len ; idx++){
        if(maxNumber < nums[idx]){
            maxNumber = nums[idx];
            maxIdx = idx;
        }
    }
    return maxIdx;
}



int main(){
    int len;
    std::cin >> len;
    std::vector<int> nums(len);

    for(int idx = 0 ; idx < len ; idx++){
        std::cin >> nums[idx];
    }

    int minSwaps = 0;

    int minIdx = findMinIdx(nums);
    int maxIdx = findMaxIdx(nums);

    minSwaps = maxIdx + (len - 1 - minIdx);

    if(maxIdx > minIdx) minSwaps--; 

    std::cout << minSwaps;
}