#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n{};
    cin >> n;
    
    // Vector to hold {visited_value, steps_taken}
    // We reserve n * 65 because no path will exceed ~60 steps.
    vector<pair<int, int>> states;
    states.reserve(n * 65);

    for (int i = 0; i < n; i++) {
        int a{};
        cin >> a;
        
        long long curr {a};
        int steps {0};
        
        // Trace the path strictly downwards until we hit the 1-2 cycle
        while (curr > 2) {
            states.push_back({curr, steps});
            if (curr % 2 == 0) {
                curr /= 2;
            } else {
                curr += 1;
            }
            steps++;
        }
        
        // Explicitly handle the 1-2 cycle at the end of the path
        if (curr == 2) {
            states.push_back({2, steps});
            states.push_back({1, steps + 1});
        } else if (curr == 1) {
            states.push_back({1, steps});
            states.push_back({2, steps + 1});
        }
    }

    // Sort by visited_value first. 
    // This groups all occurrences of the same target value together.
    sort(states.begin(), states.end());

    long long min_total_cost {-1}; // -1 represents "infinity"
    
    int current_val {states[0].first};
    long long current_cost_sum {0};
    int count {0};

    // Slide through the sorted array to find blocks of size N
    for (int i {0}; i < states.size(); i++) {
        if (states[i].first == current_val) {
            count++;
            current_cost_sum += states[i].second;
        } else {
            // If the block size is N, every array element reached this value
            if (count == n) {
                if (min_total_cost == -1 || current_cost_sum < min_total_cost) {
                    min_total_cost = current_cost_sum;
                }
            }
            // Reset for the new value block
            current_val = states[i].first;
            current_cost_sum = states[i].second;
            count = 1;
        }
    }
    
    // Catch the final block after the loop finishes
    if (count == n) {
        if (min_total_cost == -1 || current_cost_sum < min_total_cost) {
            min_total_cost = current_cost_sum;
        }
    }

    cout << min_total_cost << "\n";
}

int main() {
    
    int t{};
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}