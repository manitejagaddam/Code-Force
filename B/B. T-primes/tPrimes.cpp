#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

// Precompute primes up to sqrt(10^12) = 10^6
vector<bool> sievePrime(1000001, true);

void buildSieve() {
    sievePrime[0] = sievePrime[1] = false;
    for(ll i = 2; i * i <= 1000000; i++) {
        if(sievePrime[i]) {
            for(ll j = i * i; j <= 1000000; j += i) {
                sievePrime[j] = false;
            }
        }
    }
}

bool isPerfectSquare(ll num, ll &root) {
    root = sqrt(num);
    return (root * root == num);
}

string solve() {
    ll num;
    cin >> num;

    // T-prime condition : perfect square + sqrt is prime
    ll root;
    if(isPerfectSquare(num, root) && sievePrime[root])
        return "YES";
    return "NO";
}

int main() {

    buildSieve();

    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
