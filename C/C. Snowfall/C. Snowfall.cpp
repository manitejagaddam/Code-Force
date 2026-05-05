#include <iostream>
#include <vector>
using namespace std;



// void solve(){
//     int len {};
//     cin >> len;
//     vector<int> nums(len, 0);
//     for(int idx = 0 ; idx < len ; idx++){
//         cin >> nums[idx];
//     }

//     int start = 0;
//     for(int idx = 0 ; idx < len ; idx++){
//         if(nums[idx] % 6 == 0) swap(nums[idx], nums[start++]);
//     }

//     int end = len - 1;
//     for(; end >= start ; end--){
//         if(nums[end] % 3 == 0) break;
//     }

//     for(int ele : nums) cout << ele << " ";
//     cout << endl;

//     cout << "End : " << end << " Start : " << start << endl;

//     for(int idx = start ; idx < len - 1 ; idx ++){

//         if(nums[idx] % 2 == 0 && nums[idx + 1] % 3 == 0){
//             cout << "Swap Happend Between " << idx << " " << end << endl;
//             swap(nums[idx], nums[end--]);
//             while(end >= start && nums[end] % 3 != 0) end--;
//         }

//         else if(nums[idx] % 3 == 0 && nums[idx + 1] % 2 == 0){
//             cout << "Swap Happend Between " << idx + 1 << " " << end << endl;
//             swap(nums[idx + 1], nums[end--]);
//             // int temp {nums[idx + 1]};
//             // nums[idx + 1] = nums[end];
//             // nums[end] = temp;
//             while(end >= start && nums[end] % 3 != 0) end--;
//         }
//     }

//     for(int ele : nums) cout << ele << " ";
//     cout << endl;
// }




void solve(){
    int len {};
    cin >> len;
    vector<int> nums(len, 0);
    for(int idx = 0 ; idx < len ; idx++) cin >> nums[idx];
    
    vector<int> div6;
    vector<int> div2;
    vector<int> div3;
    vector<int> neither;

    for (int i = 0; i < len; i++) {
        if (nums[i] % 6 == 0) {
            div6.push_back(nums[i]);
        } else if (nums[i] % 2 == 0) {
            div2.push_back(nums[i]);
        } else if (nums[i] % 3 == 0) {
            div3.push_back(nums[i]);
        } else {
            neither.push_back(nums[i]);
        }
    }


    vector<int> ans;
    
    ans.insert(ans.end(), div6.begin(), div6.end());
    ans.insert(ans.end(), div2.begin(), div2.end());
    ans.insert(ans.end(), neither.begin(), neither.end());
    ans.insert(ans.end(), div3.begin(), div3.end());

    for (int ele : ans) cout << ele << " ";
    cout << endl;
}


int main(){
    int t{};
    cin >> t;
    while(t--) solve();
    return 0;
}