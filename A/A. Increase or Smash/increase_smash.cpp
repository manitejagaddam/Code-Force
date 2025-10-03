#include <iostream>
#include <unordered_set>
#include <vector>



int solve(){
    int len;
    std::cin >> len;
    std::vector<int> nums(len);
    std::unordered_set<int> st;
    for(int idx = 0 ; idx < len ; idx++){
        int temp;
        std::cin >> temp;
        nums[idx] = temp;
        st.insert(temp);
    }
    // if(st.count(0)) st.erase(0);

    // return st.count(0) ? st.size() * 2 : st.size() * 2 - 1;
    return st.size() * 2 - 1;
}
    

int main(){
    int no_test_cases;
    std::cin >> no_test_cases;
    while(no_test_cases--) std::cout << solve() << std::endl;
    return 0;
}