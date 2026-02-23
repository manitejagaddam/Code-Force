#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void addDigits(vector<int> & nums, long long n){
    while(n){
        nums.push_back(n % 10);
        n /= 10;
    }
    reverse(nums.begin(), nums.end());
}


string solve(){
    long long n;
    cin >> n;
    vector<int> nums;
    addDigits(nums, n);
    int count_2 = 0, count_3 = 0;
    // int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int total_sum = 0;
    for(int ele : nums){
        if(ele == 2) count_2++;
        else if(ele == 3) count_3++;
        total_sum += ele;
    }

    if(total_sum % 9 == 0) {
        return "YES";
    }

    int req = 9 - (total_sum % 9);

    while(req >= 6 && count_3){
        count_3--;
        req-= 6;
    }
    while(req >= 2 && count_2){
        count_2--;
        req -= 2;
    }
    if(req == 0) {
        return "YES";
    }
    return "NO";

}

int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--){
        cout << solve() << endl;
    }
    return 0;
}