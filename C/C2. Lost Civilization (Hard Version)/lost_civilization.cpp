#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct node {
    int val;
    int idx;
    int bound;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<node> s;
    ll total_ans = 0;

    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && s.back().val > a[i]) {
            s.pop_back();
        }

        int current_bound = 0;

        if (s.empty()) {
            current_bound = 0;
        } else if (s.back().val == a[i]) {
            current_bound = s.back().bound;
        } else if (s.back().val == a[i] - 1) {
            current_bound = s.back().idx;
        } else {
            current_bound = 0;
            s.clear();
        }

        s.push_back({a[i], i, current_bound});
        
        total_ans += (ll)(i - current_bound) * (n - i + 1);
    }

    cout << total_ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}