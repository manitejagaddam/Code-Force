#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int solve(){
    int maxi = -100;
    int temp = -100;
    int totalSum = 0;
    for(int idx = 0 ; idx < 7 ; idx++){
        cin >> temp;
        totalSum += temp;
        maxi = maxi < temp ? temp : maxi;
    }

    // cout << totalSum << "   " << maxi << "   " << endl << endl;
    return -totalSum + 2 * maxi;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}