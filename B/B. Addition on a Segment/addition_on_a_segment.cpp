#include <iostream>
#include <vector>
using namespace std;



int solve(){
    int len;
    cin >> len;
    vector<int> nums(len);

    int no_zero = 0;
    int sum = 0;
    for(int idx = 0 ; idx < len ; idx++){
        int temp ;
        cin >> temp;
        nums[idx] = temp;
        if(temp > 0) no_zero++;
        sum += temp;
    }

    return min(no_zero, (sum - len + 1 < 0) ? 1 : sum - len + 1);

}



int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--) cout << solve() << endl;
    return 0;
}