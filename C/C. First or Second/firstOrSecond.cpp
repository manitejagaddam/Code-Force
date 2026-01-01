#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;


void solve() {
    int len;
    cin >> len;
    vector<long long> nums(len + 1); 
    for (int i = 1; i <= len; i++) {
        cin >> nums[i];
    }

    vector<long long> prefAbs(len + 2, 0);
    for (int i = 2; i <= len; i++) {
        prefAbs[i] = prefAbs[i - 1] + abs(nums[i]);
    }

    vector<long long> suff(len + 2, 0);
    for (int i = len; i >= 1; i--) {
        suff[i] = suff[i + 1] + nums[i];
    }

    long long max_x = -2e18; 

    for (int k = 1; k <= len; k++) {
        long long current_x;
        
        if (k == 1) {
            current_x = -suff[2];
        } else {
            
            long long prefix_part = nums[1] + prefAbs[k - 1];
            long long suffix_part = suff[k + 1];
            
            current_x = prefix_part - suffix_part;
        }

        if (current_x > max_x) {
            max_x = current_x;
        }
    }

    cout << max_x << endl;
}

int main() {

    int no_test_cases;
    cin >> no_test_cases;
    while (no_test_cases--) {
        solve();
    }
    return 0;
}