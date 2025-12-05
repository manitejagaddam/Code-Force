#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Get all divisors of n
vector<ll> getDivisors(ll n) {
    vector<ll> div;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            div.push_back(i);
            if(i * i != n) div.push_back(n / i);
        }
    }
    return div;
}

ll solve() {
    ll N, a, b, c;
    cin >> N >> a >> b >> c;

    vector<ll> div = getDivisors(N);
    sort(div.begin(), div.end());

    ll ans = 0;

    for(ll x : div) {
        if(x > a) break;     // sorted → no need to check further
        ll M = N / x;

        // find divisors of M quickly using pre-known divisors of N
        for(ll y : div) {
            if(y > b) break; // sorted
            if(y * y > M) break;
            if(M % y != 0) continue;

            ll z = M / y;
            if(z <= c && z > 0) ans++;

            // check symmetrical divisor pair (y != z)
            if(y != z && z <= b && y <= c) ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        cout << solve() << "\n";
    }
    return 0;
}
