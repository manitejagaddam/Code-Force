#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int strength, len;
    cin >> strength >> len;
    vector<pair<int, int>> nums;
    for(int idx = 0 ; idx < len ; idx++){
        int in, out;
        cin >> out >> in;
        nums.push_back({out, in});
    }
    sort(nums.begin(), nums.end());
    for(auto it : nums){
        int out = it.first;
        int in = it.second;
        if(out >= strength) {
            cout << "NO";
            return 0;
        }
        strength += in;
    }
    cout << "YES";
    return 0;
}