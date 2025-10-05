#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
void solve() {
    int n;
    cin >> n;

    vector<int> candidates(n);
    iota(candidates.begin(), candidates.end(), 1);

    while (candidates.size() > 2) {
        int pivot = candidates[0];
        
        for (int i = candidates.size() - 1; i >= 1; --i) {
            cout << pivot << " " << candidates[i] << endl;
            int result;
            cin >> result;
            if (result == 1) {
                return;
            }
        }

        candidates.erase(candidates.begin());
    }

    cout << candidates[0] << " " << candidates[1] << endl;
    int result;
    cin >> result;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}