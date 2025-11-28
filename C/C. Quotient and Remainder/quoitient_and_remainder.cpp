#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<long long> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    vector<long long> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    vector<long long> capacities;
    capacities.reserve(n);
    
    for (int i = 0; i < n; ++i) {
        if (r[i] < k) {
            long long capacity = (k - r[i]) / (r[i] + 1);
            capacities.push_back(capacity);
        } else {
            capacities.push_back(0); 
        }
    }

    sort(q.begin(), q.end());
    sort(capacities.begin(), capacities.end());

    int matches = 0;
    int r_ptr = 0; 
    int q_ptr = 0; 

    while (q_ptr < n && r_ptr < n) {
        if (capacities[r_ptr] >= q[q_ptr]) {
            matches++;
            q_ptr++;
            r_ptr++;
        } else {
            r_ptr++;
        }
    }

    cout << matches << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}