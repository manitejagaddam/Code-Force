#include <bits/stdc++.h>
using namespace std;


void findNumberOfPartitions(vector<int> & nums){
    unordered_map<int, int> mpp;
    for(int i : nums) mpp[i]++;
    
    cout << mpp[nums[0]];
    return;
}

void solve(){
    int noe; //no of elements
    cin >> noe;
    vector<int> nums(noe);
    for(int idx = 0 ; idx < noe ; idx++){
        cin >> nums[idx];
    }

    findNumberOfPartitions(nums);

    return;
}


int main(){
    int notc; // no of test cases
    cin >> notc;

    for(int test_case = 0 ; test_case < notc ; test_case++){
        solve();
        cout << endl;
    }

    return 0;

}