#include <iostream>
#include <vector>
using namespace std;



bool isPrime(int num){
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int idx = 5 ; idx * idx <= num ; idx += 6){
        if(num % idx == 0 || num % (idx + 2) == 0) return false;
    }
    return true;
}

int main(){
    int num;
    cin >> num;
    vector<int> order;
    
    // while(num){
        
    //     while(num > 3) {
    //         order.push_back(2);
    //         num -= 2;
    //     }
    //     if(num == 3) {
    //         order.push_back(3);
    //         num -= 3;
    //     }
    //     else if(num == 2) order.push_back(2);
    //     num -= 2;
    // }
    // cout << order.size() << endl;
    // for(int ele : order) cout << ele << " ";
    // return 0;
    int two_ = num / 2;
    if(num % 2 == 0){
        cout << two_ << endl;
        for(int idx = 0 ; idx < two_ ; idx++) cout << 2 << " ";
    } else{
        cout << two_ << endl;
        for(int idx = 0 ; idx < two_ - 1; idx++) cout << 2 << " ";
        cout << 3;
    }


}