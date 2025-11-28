#include <iostream>
using namespace std;



int solve(){
    int n;
    cin >> n;
    if(n == 1) return 1;
    if(n == 2) return 9;
    if(n == 3) return 29;
    if(n == 4) return 56;
    // return ((n * n - 1) + (n * (n - 1) - 1) + (n * (n - 1) - 2) + (n * (n - 1)) + (n * (n - 2) - 1));
    // return 4LL*n*n - 6LL*n + 6;
    return 5 * (n * n - n - 1);
}



int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--){
        cout << solve() << endl;;
    }

    return 0;
}