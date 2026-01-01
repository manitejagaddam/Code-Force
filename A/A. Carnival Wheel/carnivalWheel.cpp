#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    vector<bool> visited(l, false);
    
    int current = a;
    int max_prize = a;
    while (!visited[current]) {
        visited[current] = true;
    
        if (current > max_prize) {
            max_prize = current;
        }
        current = (current + b) % l;
    }

    cout << max_prize << endl;
}

int main() {

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}