#include <iostream>
#include <vector>
using namespace std;

#define ll long long



ll solve(ll num, ll k){
    vector<ll> small, large;
    for(ll idx = 1 ; idx * idx <= num ; idx++){
        if(num % idx == 0){
            small.push_back(idx);
            if(idx != num / idx) large.push_back(num / idx);
        } 
    }

    ll total = small.size() + large.size();

    if(k > total) return -1;

    if(k <= (long long)small.size()) return small[k - 1];

    return large[total - k];
}



int main(){
    ll num, k;
    cin >> num >> k;
    cout << solve(num, k);
    return 0;
}