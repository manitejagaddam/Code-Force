#include <iostream>
#include <unordered_map>
#include <climits>

int dfs(int num, int target, std::unordered_map<int,int> &memo) {
    if(num == target) return 0;
    if(num <= 0) return INT_MAX; 
    if(memo.count(num)) return memo[num];

    int ans = INT_MAX;

    int sub = dfs(num - 1, target, memo);
    if(sub != INT_MAX) ans = std::min(ans, sub + 1);

    if(num < target) {
        int mult = dfs(num * 2, target, memo);
        if(mult != INT_MAX) ans = std::min(ans, mult + 1);
    }

    return memo[num] = ans;
}

int main() {
    int num, target;
    std::cin >> num >> target;

    std::unordered_map<int,int> memo;
    int ans = dfs(num, target, memo);
    std::cout << ans << std::endl;
    return 0;
}
