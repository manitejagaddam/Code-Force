#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll computeGCD(ll a, ll b) {
    return __gcd(a, b);
}

ll findArrayGCD(const vector<ll> &arr) {
    ll g = 0;
    for(ll x : arr) {
        g = computeGCD(g, x);
    }
    return g;
}

ll countDivisors(ll num) {
    ll cnt = 0;
    for(ll i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            cnt++;
            if(i * i != num) cnt++; // pair divisor
        }
    }
    return cnt;
}

ll solve() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll g = findArrayGCD(arr);
    return countDivisors(g);
}

int main() {

    cout << solve() << "\n";
    return 0;
}
