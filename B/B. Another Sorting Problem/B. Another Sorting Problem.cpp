#include <iostream>
#include <vector>

using namespace std;




void solve(){
    int n{};
    cin >> n;

    vector<int> a(n, {0});
    
    for(int idx = 0 ; idx < n ; idx++){
        cin >> a[idx];
    }
    
    if(n == 1) {
        cout << "YES" << endl;
        return;
    }
    // int idx{1};
    

    // vector<int> prefixMax(n, {0});
    // prefixMax[0] = nums[0];

    // for(idx = 1 ; idx < n ; idx++){
    //     prefixMax[idx] = prefixMax[idx - 1] < nums[idx] ? nums[idx] : prefixMax[idx - 1];
    // }

    // vector<int> suffixMin(n, {0});
    // suffixMin[n - 1] = nums[n - 1];

    // for(idx = n - 2 ; idx >= 0 ; idx--){
    //     suffixMin[idx] = suffixMin[idx + 1] > nums[idx] ? nums[idx] : suffixMin[idx + 1];
    // }

    // vector<bool> flags(n, {false});

    // // flag a -> need to change the values
    // // flag b -> need not to change the values

    // bool flagA = false;
    // bool flagB = false;


    // for(idx = 0 ; idx < n ; idx++){
    //     flagA = nums[idx] < prefixMax[idx]; // needs to catch up (BOOST)
    //     flagB = nums[idx] > suffixMin[idx]; // needs to let others catch up (STAY)

    //     if(flagA && flagB){
    //         cout << "NO" << endl;
    //         return;
    //     }

    //     // true = BOOST, false = STAY
    //     if(flagA) flags[idx] = true; 
    //     else flags[idx] = false;
    // }
    

    // int minK = 0;
    // int maxK = 2e9;


    // for(idx = 0 ; idx < n - 1 ; idx++){
    //     if(!flags[idx] && flags[idx + 1]){
    //         // idx STAYS (false), idx+1 BOOSTS (true). 
    //         // idx+1 must catch up to idx. Sets minK.
    //         int diff = nums[idx] - nums[idx + 1];
    //         minK = minK < diff ? diff : minK; // Find max of all required boosts
            
    //     } else if(flags[idx] && !flags[idx + 1]){
    //         // idx BOOSTS (true), idx+1 STAYS (false). 
    //         // idx cannot overtake idx+1. Sets maxK.
    //         int diff = nums[idx + 1] - nums[idx];
    //         maxK = maxK > diff ? diff : maxK; // Find min of all allowed limits
            
    //     } else if(flags[idx] == flags[idx + 1]){
    //         // Same group. Must already be sorted.
    //         if(nums[idx] > nums[idx + 1]){
    //             cout << "NO" << endl;
    //             return;
    //         }
    //     }
    // }

    // if(minK <= maxK) cout << "YES" << endl;
    // else cout << "NO" << endl;
    // return;


    int minK = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            minK = max(minK, a[i] - a[i + 1]);
        }
    }

    // 2. Greedily verify if minK works
    // We want to keep every element as small as possible so the next element can easily beat it.
    long long prev = -2e9; // Use long long to prevent overflow when adding minK
    
    for (int i = 0; i < n; i++) {
        if (a[i] >= prev) {
            // First choice: Don't boost it. Keep it as small as possible.
            prev = a[i];
        } else if (a[i] + minK >= prev) {
            // Second choice: It's too small, so boost it by minK.
            prev = a[i] + minK;
        } else {
            // Even with the boost, it can't catch up to the previous number.
            cout << "NO\n";
            return;
        }
    }

    // If we made it through the whole array, it's sortable!
    cout << "YES\n";
    return;

}


int main(){
    int t{};
    cin >> t;
    while(t--) solve();

    return 0;
}