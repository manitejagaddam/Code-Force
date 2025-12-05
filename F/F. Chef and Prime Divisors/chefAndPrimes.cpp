#include <bits/stdc++.h>
using namespace std;

#define ll long long


bool isPrime(ll num){
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(ll idx = 5 ; idx * idx <= num ; idx += 6){
        if(num % idx == 0 || num % (idx + 2) == 0) return false;
    }
    return true;
}


string solve(){
    ll num1, num2;
    cin >> num1 >> num2;
    if(isPrime(num2)) return num1 == num2 ? "YES" : "NO";
    if(isPrime(num1)) return num1 % num2 == 0 ? "YES" : "NO";

    if(num2 % 2 == 0 && num1 % 2 == 1) return "NO";
    
    for(ll idx = 3 ; idx < num2 ; idx += 2){
        if(isPrime(idx) && num2 % idx == 0 && num1 % idx == 1) return "NO";
    }
    return "YES";

}

int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--) cout << solve() << endl;
    return 0;
}