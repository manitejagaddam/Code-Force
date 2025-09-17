#include <iostream>



void solve(){
    int x, n;
    std::cin >> x >> n;
    if(n % 2 == 1) std::cout << x;
    else std::cout << 0;
    std::cout << std::endl;

    return;
}


int main(){
    int no_test_cases;
    std::cin >> no_test_cases;
    while(no_test_cases--){
        solve();
    }
    return 0;
}