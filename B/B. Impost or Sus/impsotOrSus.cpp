
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string str;
    cin >> str;
    int n = str.length();
    int ans = 0;

    if (str[0] == 'u') {
        ans++;
        str[0] = 's';
    }
    if (str[n - 1] == 'u') {
        ans++;
        str[n - 1] = 's';
    }

    for (int idx = 0; idx < n; ) {
        if (str[idx] == 'u') {
            int start = idx;
            while (idx < n && str[idx] == 'u') {
                idx++;
            }
            int k = idx - start;
            ans += k / 2; 
        } else {
            idx++;
        }
    }

    cout << ans << endl;
}

int main() {

    int no_test_cases;
    cin >> no_test_cases;
    while (no_test_cases--) {
        solve();
    }
    return 0;
}