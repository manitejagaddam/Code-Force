#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void calculate_costs(int layers, bool start_with_white, long long &needed_white, long long &needed_dark) {
    needed_white = 0;
    needed_dark = 0;
    long long current_size = 1;
    
    for (int i = 0; i < layers; ++i) {
        
        bool is_white_layer;
        if (start_with_white) {
            is_white_layer = (i % 2 == 0);
        } else {
            is_white_layer = (i % 2 != 0);
        }

        if (is_white_layer) {
            needed_white += current_size;
        } else {
            needed_dark += current_size;
        }
        
        current_size *= 2;
    }
}

void solve() {
    long long a, b;
    cin >> a >> b;

    int max_layers = 0;
    
    
    for (int k = 1; k <= 60; ++k) {
        long long w_req, d_req;
        bool possible = false;

        calculate_costs(k, true, w_req, d_req);
        if (a >= w_req && b >= d_req) {
            possible = true;
        }

        calculate_costs(k, false, w_req, d_req);
        if (a >= w_req && b >= d_req) {
            possible = true;
        }

        if (possible) {
            max_layers = k;
        } else {
            break;
        }
    }

    cout << max_layers << endl;
}

int main() {
    int no_test_cases;
    cin >> no_test_cases;
    while (no_test_cases--) {
        solve();
    }
    return 0;
}