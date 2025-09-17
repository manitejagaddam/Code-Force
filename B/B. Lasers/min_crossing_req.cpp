#include <iostream>
#include <vector>



void solve(){
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<int> vertical(n);
    std::vector<int> horizontal(m);
    for(int idx = 0 ; idx < n ; idx++){
        std::cin >> vertical[idx];
    }

    for(int idx = 0 ; idx < m ; idx++){
        std::cin >> horizontal[idx];
    }
    
    std::cout << m + n << std::endl;
    // std::cout << "Ans: " << m + n << std::endl;
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