#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int count_a = 0;
    int count_b = 0;
    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else {
            count_b++;
        }
    }

    if (count_a == count_b) {
        std::cout << 0 << std::endl;
        return;
    }

    int k = count_a - count_b;

    std::map<int, int> diff_to_pos;
    diff_to_pos[0] = 0; 
    
    int current_diff = 0;
    int min_len = n + 1; 

    for (int i = 0; i < n; ++i) {
        current_diff += (s[i] == 'a' ? 1 : -1);

        int target_diff = current_diff - k;
        if (diff_to_pos.count(target_diff)) {
            int start_pos = diff_to_pos[target_diff];
            min_len = std::min(min_len, (i + 1) - start_pos);
        }
        
        diff_to_pos[current_diff] = i + 1;
    }
    
    if (min_len > n) { 
        std::cout << -1 << std::endl;
    } else if (min_len == n) {
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << min_len << std::endl;
    }
}

int main() {
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}