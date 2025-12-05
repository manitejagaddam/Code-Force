#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n_in;
    long long k;
    if (!(cin >> n_in >> k)) return;
    
    vector<int> a(n_in);
    for(int i=0; i<n_in; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int n = a.size();
    
    vector<vector<int>> valid_indices(n);
    vector<bool> is_valid(n, false);
    
    for (int i = 0; i < n; i++) {
        long long val = a[i];
        
        if (k / val > n) {
            continue;
        }

        bool ok = true;
        for (long long m = val; m <= k; m += val) {
            auto it = lower_bound(a.begin(), a.end(), (int)m);
            if (it != a.end() && *it == m) {
                valid_indices[i].push_back(distance(a.begin(), it));
            } else {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            is_valid[i] = true;
        } else {
            vector<int>().swap(valid_indices[i]);
        }
    }

    vector<bool> is_covered(n, false);
    vector<int> solution;

    for (int i = 0; i < n; i++) {
        if (is_covered[i]) continue;

        if (is_valid[i]) {
            solution.push_back(a[i]);
            for (int idx : valid_indices[i]) {
                is_covered[idx] = true;
            }
        }
    }

    bool all_covered = true;
    for(int i=0; i<n; i++) {
        if (!is_covered[i]) {
            all_covered = false;
            break;
        }
    }

    if (all_covered) {
        cout << solution.size() << "\n";
        for(int i=0; i<solution.size(); i++) cout << solution[i] << (i==solution.size()-1?"":" ");
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) solve();
    }
    return 0;
}