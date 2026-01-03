#include <iostream>
using namespace std;


long long power(int a, int b){
    long long ans = 1;
    while(b){
        ans *= a;
        b--;
    }
    return ans;
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << power(a, b) - power(b, a);
    return 0;
}