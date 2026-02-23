#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int shortest_length = 0;
    vector<int> stack;

    for (int x : a) {
        while (!stack.empty() && stack.back() > x - 1) {
            stack.pop_back();
        }

        if (!stack.empty() && stack.back() == x - 1) {
            stack.push_back(x);
        } else {
            shortest_length++;
            stack.clear();
            stack.push_back(x);
        }
    }

    cout << shortest_length << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}