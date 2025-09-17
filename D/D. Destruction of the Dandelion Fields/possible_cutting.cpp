#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(){
    int len;
    cin >> len;
    vector<int> nums(len);
    // long long max_odd = -1;
    vector<long long> odds;

    long long even_sum = 0;
    for(int idx = 0 ; idx < len ; idx++){
        long long temp;
        cin >> temp;
        if(temp % 2 == 1) odds.push_back(temp);
        else even_sum += temp;
    }

    if(odds.size() > 0){
        int size = (odds.size() + 1) / 2;

        long long oddsum = 0;
        sort(odds.rbegin(), odds.rend());
        for(int idx = 0 ; idx < size ; idx++) oddsum += odds[idx];


        cout << even_sum + oddsum << endl;
    }else cout << 0 << endl;

    return;
}


int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--) solve();
    return 0;
}