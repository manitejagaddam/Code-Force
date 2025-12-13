#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(const vector<int>& a) {
    if (a.empty()) return; 
    long long maxi = *max_element(a.begin(), a.end());

    vector<long long> rem;
    for (long long ele : a) {
        long long diff = maxi - ele;
        if (diff > 0) {
            rem.push_back(diff);
        }
    }

    long long z; 
    long long len = rem.size();

    if (len == 1) {
        z = rem[0];
    } else {
        z = rem[0];
        for (size_t idx = 1; idx < len; ++idx) {
            z = __gcd(z, rem[idx]); 
        }
    }

    long long y_min = 0;
    for (long long ele : rem) {
        y_min += ele / z; 
    }

    cout << y_min << " " << z << endl;
}


int main(){
    int len;
    cin >> len;
    vector<int> a(len);
    for(int idx = 0 ; idx < len ; idx++) cin >> a[idx];
    solve(a);
    return 0;
}