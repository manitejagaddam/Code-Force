#include <iostream>
#include <string>




// int convertNum(int num){
//     int temp_num = 0;
//     while(num){
//         if(num == 9) {
//             temp_num = temp_num * 10 + num;
//             return temp_num;
//         }
//         int digit = num % 10;
//         if(digit > 4) digit = 9 - digit;
//         temp_num = temp_num * 10 + digit;
//         num /= 10;
//     }
//     return temp_num;
// }


// int revNum(int num){
//     int rev_num = 0;
//     while(num){
//         rev_num = (rev_num * 10) + (num % 10);
//         num /= 10;
//     }
//     return rev_num;
// }




// int main(){
//     int num;
//     std::cin >> num;
//     num = convertNum(num);
//     num = revNum(num);

//     std::cout << num;

//     return 0;
// }


void convertStr(std::string & s){
    int len = s.length();
    for(int idx = 0 ; idx < len ; idx++){
        if(idx == 0 && s[idx] == '9') continue;
        if(s[idx] > '4'){
            // std::cout << s[idx] << " " << '9' - s[idx] << " ";
            s[idx] = char('0' + ('9' - s[idx]));
        }
    }
    // std::cout << std::endl;
    // std::cout << s << std::endl;
}

int main(){
    std::string s;
    long long num;

    std::cin >> num;
    s = std::to_string(num);

    convertStr(s);

    num = std::stoll(s);

    std::cout << num;
    return 0;
}