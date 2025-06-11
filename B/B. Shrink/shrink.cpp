#include <bits/stdc++.h>
using namespace std;




void createArray(int size){
    vector<int> nums(size);
    int first = 0;
    int last = size - 1;
    int no = 1;
    while(first < last){
        nums[first++] = no++;
        nums[last--] = no++;
    }
    if(size % 2 == 1) nums[first] = no;
    for(int i : nums) cout << i << " ";
    return;
}


void solve(){
    int size;
    cin >> size;

    createArray(size);

    return;
}


int main(){
    int notc; // no of test cases
    cin >> notc;

    for(int test_case = 0 ; test_case < notc ; test_case++){
        solve();
        cout << endl;
    }

    return 0;

}