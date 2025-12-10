#include <iostream>
using namespace std;


int main(){
    int k;
    cin >> k;

    if(k < 6) {
        cout << 1;
        return 0;
    }

    int count = k / 5;
    if(count * 5 == k) {
        cout << count;
        return 0;
    }
    cout << count + 1;


    // for(int val = 5 ; val > 0 && k > 0 ; val--){
    //     count += k / val;
    //     k -= (val * (k / val));
    // }
    // cout << count;
    return 0;


}