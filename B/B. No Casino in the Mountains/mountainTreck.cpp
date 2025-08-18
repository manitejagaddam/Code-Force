#include <bits/stdc++.h>

/*
You are given an array a of n numbers and a number k. The value ai describes the weather on the i-th day: if it rains on the i-th day, then ai=1; otherwise, if the weather is good on the i-th day, then ai=0.

Jean wants to visit as many peaks as possible. One hike to a peak takes exactly k days, and during each of these days, the weather must be good (ai=0). That is, formally, he can start a hike on day i only if all aj=0 for all j (i≤j≤i+k−1).

After each hike, before starting the next one, Jean must take a break of at least one day, meaning that on the day following a hike, he cannot go on another hike.

Find the maximum number of peaks that Jean can visit.

Input
Each test consists of several test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n and k (1≤n≤105, 1≤k≤n).

The second line contains n numbers ai (ai∈{0,1}), where ai denotes the weather on the i-th day.

It is guaranteed that the total value of n across all test cases does not exceed 105.

Output
For each test case, output a single integer: the maximum number of hikes that Jean can make.

Example
InputCopy
5
5 1
0 1 0 0 0
7 3
0 0 0 0 0 0 0
3 1
1 1 1
4 2
0 1 0 1
6 2
0 0 1 0 0 0
OutputCopy
3
2
0
0
2

*/

bool isPossible(std::vector<int> &nums, int start, int k) {
    for (int j = start; j < start + k; j++) {
        if (nums[j] == 1) return false;
    }
    return true;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) std::cin >> nums[i];

    int no_treck_possible = 0;
    int i = 0;
    while (i <= n - k) {
        if (isPossible(nums, i, k)) {
            no_treck_possible++;
            i += k + 1; 
        } else {
            i++;
        }
    }
    std::cout << no_treck_possible << std::endl;
}


int main(){

    int no_test_cases;
    std::cin >> no_test_cases;

    for(int test_case = 0 ; test_case < no_test_cases ; test_case++){
        solve();
    }

    return 0;

}