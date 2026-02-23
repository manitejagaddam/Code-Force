#include <iostream>
using namespace std;

#define ll long long


string solve(){
    ll x, y;
    cin >> x >> y;
    
    if(y > 0) {
        x -= 2 * y;
        y = 0;
    }else if(y < 0){
        x -= 4 * -y;
        y = 0;
    }
    return x % 3 == 0 ? (x >= 0 ? "YES" : "NO") : "NO";
}

int main(){
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        cout << solve() << endl;
    }
    return 0;
}