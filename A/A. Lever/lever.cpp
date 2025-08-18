#include <iostream>
#include <vector>


void solve(){
    int len;
    std::cin >> len;
    std::vector<int> a(len), b(len);
    for(int i = 0 ; i < len ; i++) std::cin >> a[i];
    for(int i = 0 ; i < len ; i++) std::cin >> b[i];

    int count = 1;
    for(int i = 0 ; i < len ; i++){
        if(a[i] > b[i]) count += a[i] - b[i];
    }

    std::cout << count << std::endl;
    // std::cout << "Count : " << count << std::endl;
}


int main(){
    int no_test_cases;
    std::cin >> no_test_cases;
    for(int i = 0 ; i < no_test_cases ; i++) solve();

    return 0;
}