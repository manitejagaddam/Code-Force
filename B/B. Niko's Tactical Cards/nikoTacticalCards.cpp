#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int len;
    cin >> len;

    vector<long long> nums1(len);
    vector<long long> nums2(len);

    for (int idx = 0; idx < len; idx++) cin >> nums1[idx];
    for (int idx = 0; idx < len; idx++) cin >> nums2[idx];

    long long current_max = 0;
    long long current_min = 0;

    for (int idx = 0; idx < len; idx++) {
        
        long long red_option_max = current_max - nums1[idx];
        long long red_option_min = current_min - nums1[idx];

        long long blue_option_max = nums2[idx] - current_min;
        long long blue_option_min = nums2[idx] - current_max;

        current_max = max(red_option_max, blue_option_max);
        current_min = min(red_option_min, blue_option_min);
    }

    cout << current_max << endl;
}

int main() {
    int no_test_cases;
    cin >> no_test_cases;
    while (no_test_cases--) {
        solve();
    }
    return 0;
}