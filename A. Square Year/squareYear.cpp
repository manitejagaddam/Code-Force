#include <bits/stdc++.h>
using namespace std;




void squareYear(){
    int num;
    cin >> num;
    int sqrt_num = sqrt(num);
    if(sqrt_num * sqrt_num != num){
        cout << -1 << endl;
        return;
    }
    if(sqrt_num % 2 == 0){
        cout << sqrt_num / 2 - 1 << " " << sqrt_num / 2 + 1 << endl;
        return;
    }else{
        cout << sqrt_num / 2  << " " << sqrt_num / 2 + 1 << endl;
        return;
    }
    return;
}



int main(){
    int no_test_cases;
    cin >> no_test_cases;

    for(int test_case = 0 ; test_case < no_test_cases ; test_case++){
        squareYear();
    }

    return 0;
}