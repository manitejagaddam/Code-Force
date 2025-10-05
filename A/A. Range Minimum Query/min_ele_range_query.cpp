#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
    Square Root Decomposition for Range Minimum Query
    - Preprocess in blocks of size sqrt(n)
    - Query: min in [l, r] in O(sqrt(n))
*/

// Function to preprocess block minimums
void preprocess(const vector<long long>& nums, vector<long long>& blockMin, int blockSize) {
    int n = nums.size();
    int noBlocks = (n + blockSize - 1) / blockSize; // number of blocks
    blockMin.assign(noBlocks, LLONG_MAX);

    for(int i = 0; i < n; i++){
        int block = i / blockSize;
        blockMin[block] = min(blockMin[block], nums[i]);
    }
}

// Query function using sqrt decomposition
long long query(const vector<long long>& nums, const vector<long long>& blockMin,
                int l, int r, int blockSize) {
    long long ans = LLONG_MAX;
    int n = nums.size();

    while(l <= r){
        // If current l is at the start of a block and whole block fits in [l, r]
        if(l % blockSize == 0 && l + blockSize - 1 <= r){
            ans = min(ans, blockMin[l / blockSize]);
            l += blockSize; // skip the whole block
        } else {
            // Partial block, check element by element
            ans = min(ans, nums[l]);
            l++;
        }
    }
    return ans;
}

// Solve function for one test case
void solve() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int blockSize = sqrt(n);
    vector<long long> blockMin;
    preprocess(nums, blockMin, blockSize);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r; 
        cout << query(nums, blockMin, l, r, blockSize) << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
