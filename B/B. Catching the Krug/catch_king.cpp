#include <iostream>
#include <algorithm>

int solve() {
    long long n, rK, cK, rD, cD;
    std::cin >> n >> rK >> cK >> rD >> cD;

    long long survival_time = 0;

    // Case 1: Doran is above Krug, so Krug runs down.
    if (rD < rK) {
        survival_time = std::max(survival_time, n - rD);
    }

    // Case 2: Doran is below Krug, so Krug runs up.
    if (rD > rK) {
        survival_time = std::max(survival_time, rD);
    }

    // Case 3: Doran is to the left of Krug, so Krug runs right.
    if (cD < cK) {
        survival_time = std::max(survival_time, n - cD);
    }

    // Case 4: Doran is to the right of Krug, so Krug runs left.
    if (cD > cK) {
        survival_time = std::max(survival_time, cD);
    }

    // std::cout << survival_time << std::endl;
    return survival_time;
}

int main() {
    int no_test_cases;
    std::cin >> no_test_cases;
    while (no_test_cases--) {
        std::cout << solve() << std::endl;
    }
    return 0;
}