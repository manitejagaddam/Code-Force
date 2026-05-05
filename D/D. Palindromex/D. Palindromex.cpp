#include <iostream>
#include <vector>
#include <numeric>
using namespace std;



pair<int, int> getLargestPalindrome(vector<int> nums){
    int start = 0;
    int maxLength = 0;
    int len = nums.size();
    for(int idx = 0 ; idx < len ; idx++){


        for(int flag = 0 ; flag <= 1 ; flag++){
            int low = idx;
            int high = idx + flag;

            while(low >= 0 && high < len && nums[low] == nums[high]){
                int currLen = high - low + 1;
                if(currLen > maxLength){
                    maxLength = currLen;
                    start = low;
                }
                low--;
                high++;
            }
        }
    }

    // cout << start << " " << start + maxLength << endl;
    // for(int idx = start ; idx < start + maxLength ; idx++) cout << nums[idx] << "  ";
    // cout << endl;
    return {start, start + maxLength};
}

int getMex(vector<int> nums, pair<int, int> boundary){
    int subarray_len = boundary.second - boundary.first;
    vector<bool> present(subarray_len + 1, false);
    
    for(int idx = boundary.first ; idx < boundary.second ; idx++) {
        if(nums[idx] <= subarray_len) {
            present[nums[idx]] = true;
        }
    }

    for(int idx = 0 ; idx <= subarray_len ; idx++) {
        if(!present[idx]) return idx;
    }
    
    return -1;
}

int solve(){
    int len{};
    cin >> len;
    len *= 2;
    vector<int> nums(len, 0);
    for(int idx = 0 ; idx < len ; idx++) cin >> nums[idx];
    pair<int, int> boundary {getLargestPalindrome(nums)};
    int mex {getMex(nums, boundary)};

    return mex;

}

int main(){
    int t{};
    cin >> t;
    while(t--) cout << solve() << endl;
    return 0;
}