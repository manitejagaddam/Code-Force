#include <iostream>
#include <algorithm>


void solve(){
    int a{}, b{}, c{};
    std::cin >> a >> b >> c;
    int minVal {std::min({std::abs(a - b), std::abs(b - c), std::abs(c - a)})};

    std::cout << minVal << "\n";
}

int main(){
    int n{};
    std::cin >> n;
    while(n--) solve();
    return 0;
}