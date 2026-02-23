#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n % 2 == 1) {
        // If n is odd, the very first character must be 'a'
        if (s[0] == 'b') {
            cout << "NO\n";
            return;
        }
        // The rest of the string is evaluated in pairs
        for (int i = 1; i < n; i += 2) {
            if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
                cout << "NO\n";
                return;
            }
        }
    } else {
        // If n is even, the whole string is evaluated in pairs
        for (int i = 0; i < n; i += 2) {
            if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    // If no pairs violated the conditions, a valid combination exists.
    cout << "YES\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}