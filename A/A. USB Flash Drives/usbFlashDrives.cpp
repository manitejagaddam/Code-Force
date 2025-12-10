#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int idx = 0 ; idx < n; idx++) cin >> nums[idx];
    sort(nums.rbegin(), nums.rend());
    int count = 0;
    int idx = 0;

    // for(int ele : nums) cout << ele << " ";
    // cout << endl << endl;

    while(k > 0){
        count++;
        k -= nums[idx];
        // cout << count << " " << k << " " << nums[idx] << endl;
        idx++;
    }
    cout << count;
    return 0;


}