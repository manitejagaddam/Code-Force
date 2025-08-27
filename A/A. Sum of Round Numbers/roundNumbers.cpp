#include <iostream>
#include <vector>



void breakNumber(int num){
    int digit_place = 1;
    int count = 0;
    std::vector<int> roundNumbers;
    while(num){
        int digit = num % 10;
        num /= 10;
        
        // std::cout << digit << " " << digit_place << "\n";
        if(digit){
            count++;
            roundNumbers.push_back(digit * digit_place);
        }
        digit_place *= 10;
    }
    std::cout << count << std::endl;
    for(int num : roundNumbers) std::cout << num << " ";
    std::cout << std::endl;

    return;
}

void solve(){
    int num;
    std::cin >> num;
    if(num < 10){
        std::cout << 1 << std::endl << num << std::endl;
        return;
    }
    breakNumber(num);

}

int main(){
    int no_test_cases;
    std::cin >> no_test_cases;
    for(int test_case = 0 ; test_case < no_test_cases ; test_case++) solve();
    return 0;
}