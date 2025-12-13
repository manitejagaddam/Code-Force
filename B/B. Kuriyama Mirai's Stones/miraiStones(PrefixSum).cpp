#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

vector<ll> solve(vector<ll> & nums, vector<vector<int>> & queries){
    vector<ll> ans;
    int len = nums.size();
    vector<ll> u_prefix(len + 1), v_prefix(len + 1);
    u_prefix[0] = 0;
    v_prefix[0] = 0;

    for(int idx = 1 ; idx < len + 1 ; idx++){
        u_prefix[idx] = u_prefix[idx - 1] + (ll)nums[idx - 1];
    }
    sort(nums.begin(), nums.end());
    for(int idx = 1 ; idx < len + 1 ; idx++){
        v_prefix[idx] = v_prefix[idx - 1] + (ll)nums[idx - 1];
    }

    for(auto query : queries){
        int type = query[0];
        int left = query[1];
        int right = query[2];

        if(type == 1){
            ans.push_back(u_prefix[right] - u_prefix[left - 1]);
        }else{
            ans.push_back(v_prefix[right] - v_prefix[left - 1]);
        }
    }
    return ans;
}


int main(){
    int len;
    cin >> len;
    vector<ll> nums(len);
    for(int idx = 0 ; idx < len ; idx++) cin >> nums[idx];

    int q_len;
    cin >> q_len;
    vector<vector<int>> queries;
    for(int idx = 0 ; idx < q_len ; idx++){
        int type, l, r;
        cin >> type >> l >> r;
        queries.push_back({type, l, r});
    }

    vector<long long> ans = solve(nums, queries);
    for(ll ele : ans) cout << ele << endl;
    return 0;
}