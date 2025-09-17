
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Prefix sum array
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    bool found = false;
    int L = 0, R = 0;

    // Try all l and r
    for (int l = 1; l < n && !found; l++) {
        for (int r = l + 1; r < n; r++) {
            int s1 = prefix[l] % 3;
            int s2 = (prefix[r] - prefix[l]) % 3;
            int s3 = (prefix[n] - prefix[r]) % 3;

            // Adjust for negative modulo
            if (s2 < 0) s2 += 3;
            if (s3 < 0) s3 += 3;

            // Check conditions
            if ((s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3)) {
                L = l;
                R = r;
                found = true;
                break;
            }
        }
    }

    cout << L << " " << R << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
