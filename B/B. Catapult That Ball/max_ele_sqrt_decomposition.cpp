#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;


void preprocess(vector<int> & nums, vector<int> & maxEle, int block_size){
    int len = nums.size();
    for(int idx = 0 ; idx < len ; idx++){
        maxEle[idx / block_size] = max(maxEle[idx / block_size], nums[idx]); 
    }
}


bool query(vector<int> & nums, vector<int> & maxEle, int left, int right){
    int maxi = nums[left++];
    int block_size = (int)sqrt(nums.size());
    while(left < right){
        if(left % block_size == 0 && left + block_size - 1 <= right){
            if(maxi < maxEle[left / block_size]) return false;
            left += block_size;
        }else {
            if(maxi < nums[left++]) return false;
        }
    }
    return true;
}

int solve(){
    int len, no_queries;
    cin >> len >> no_queries;
    vector<int> nums(len);
    for(int i = 0 ; i < len ; i++){
        cin >> nums[i];
    }

    int block_size   = (int)sqrt(len);
    int no_blocks = (len + block_size - 1) / block_size;
    vector<int> maxEle(no_blocks, INT_MIN);
    preprocess(nums, maxEle, block_size);

    int count = 0;
    while(no_queries--){
        int left, right;
        cin >> left >> right;
        left--;
        right--;

        if(query(nums, maxEle, left, right)) count++;
    }
    return count;

}   

int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--){
        cout << solve() << endl;
    }

    return 0;
}