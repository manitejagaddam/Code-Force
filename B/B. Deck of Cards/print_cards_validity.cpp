#include <iostream>
#include <string>
#include <vector>
#include <numeric>


void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    for (char c : s) {
        if (c == '0') {
            c0++;
        } else if (c == '1') {
            c1++;
        } else {
            c2++;
        }
    }

    if (k == n) {
        for (int i = 0; i < n; ++i) {
            std::cout << '-';
        }
        std::cout << std::endl;
        return;
    }

    std::string result(n, ' ');

    for (int i = 1; i <= n; ++i) {
        if (i <= c0 || i > n - c1) {
            result[i - 1] = '-';
        } 
        else if (i > c0 + c2 && i <= n - (c1 + c2)) {
            result[i - 1] = '+';
        } 
        else {
            result[i - 1] = '?';
        }
    }
    
    std::cout << result << std::endl;
}

int main() {
    int no_test_cases;
    std::cin >> no_test_cases;
    while (no_test_cases--) {
        solve();
    }
    return 0;
}