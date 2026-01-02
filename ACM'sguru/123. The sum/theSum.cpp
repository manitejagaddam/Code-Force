#include <iostream>
using namespace std;



int main(){
    int n;
    cin >> n;
    int sum = 2;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    int a = 1 , b = 1;
    n -= 2;
    while(n > 0){
        int temp = b;
        b = a + b;
        a = temp;
        sum += b;
        n--;
    }
    cout << sum;
    return 0;
}