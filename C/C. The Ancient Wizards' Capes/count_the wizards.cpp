#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i + 1] - a[i]) > 1) {
            cout << 0 << "\n";
            return;
        }
    }

    int total_solutions = 0;

    for (int b0_start = 0; b0_start <= 1; ++b0_start) {
        vector<int> b(n);
        b[0] = b0_start;
        bool is_valid_path = true;
        long long sum_b = b[0]; 

        for (int i = 1; i < n; ++i) {
            b[i] = (a[i] - a[i - 1] + 1) - b[i - 1];

            if (b[i] < 0 || b[i] > 1) {
                is_valid_path = false;
                break;
            }
            sum_b += b[i];
        }

        if (is_valid_path) {
            if (a[0] == b[0] + (long long)n - sum_b) {
                total_solutions++;
            }
        }
    }
    
    cout << total_solutions << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}