#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>
void solve() {
    int n;
    std::cin >> n;
    std::deque<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    int next_smallest = 1;
    while (!p.empty()) {
        if (p.front() == next_smallest) {
            p.pop_front();
        } else if (p.back() == next_smallest) {
            p.pop_back();
        } else {
            std::cout << "NO\n";
            return;
        }
        next_smallest++;
    }
    std::cout << "YES\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}