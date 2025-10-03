#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<long long> b(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> b[i];
    }

    // 1. Sort products in descending order.
    std::sort(a.begin(), a.end(), std::greater<long long>());

    // 2. Sort vouchers in ascending order.
    std::sort(b.begin(), b.end());

    long long total_cost = 0;
    int product_idx = 0;

    // 3. Process each voucher by grouping the most expensive available products.
    for (int i = 0; i < k; ++i) {
        long long voucher_size = b[i];

        // Check if there are enough products left to use this voucher.
        // This check prevents the out-of-bounds error.
        if (product_idx >= n) {
            break; 
        }

        // We pay for the (voucher_size - 1) most expensive items in this group.
        // For a voucher of size 1, this inner loop doesn't run, correctly adding 0 to the cost.
        for (int j = 0; j < voucher_size - 1; ++j) {
            total_cost += a[product_idx + j];
        }

        // The cheapest item in the group, a[product_idx + voucher_size - 1], is free.
        
        // Advance the product pointer past all items used in the group.
        product_idx += voucher_size;
    }

    // 4. Add the cost of any remaining products that were not part of a discount group.
    while (product_idx < n) {
        total_cost += a[product_idx];
        product_idx++;
    }

    std::cout << total_cost << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}