// #include <iostream>
// #include <algorithm>
// #include <vector>

// std::string minimiseString(std::string & s){
//     std::string minStr {""};
//     minStr += s[0];
//     int len = s.length();
//     for(int idx {1} ; idx < len ; idx++){
//         if(s[idx] == s[idx - 1]) continue;
//         minStr += s[idx];
//     }
//     std::cout << "Min Str : " << minStr << "\n";
//     return minStr;
// }

// int longestSameSubstring(std::string & s){
//     int len = s.length();
//     int maxi {0};
//     for(int idx {1} ; idx < len - 1 ; ){
//         char ch {s[idx]};

//         int curr {0};
//         while(idx < len && s[idx] == ch){
//             curr++;
//             idx++;
//         }

//         maxi = maxi < curr ? curr : maxi;

//         // skip 1 character
//         if (idx < len - 1 && ch == s[idx + 1]){
//             int next {0};
//             int idx2 {idx + 1};
//             while(idx2 < len && s[idx2] == ch){
//                 next++;
//                 idx2++;
//             }
//             maxi = maxi < curr + next + 1 ? curr + next + 1 : maxi;
//         }
//     }
//     return maxi > 0 ? maxi : 1;
// }

// void solve(){
//     int len{};
//     std::cin >> len;
//     std::string s{};
//     std::cin >> s;
//     std::string minStr{minimiseString(s)};
//     std::cout << minStr.size() - longestSameSubstring(minStr) + 1 << "\n";

// }

// int main(){
//     int n{};
//     std::cin >> n;
//     while(n--) solve();
//     return 0;
// }



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // 1. Calculate base compressed length |f(s)|
    int base_len = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            base_len++;
        }
    }

    // 2. Find the maximum reduction by deleting s[i] for 1 <= i <= n - 2
    int max_reduction = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
            if (s[i - 1] == s[i + 1]) {
                max_reduction = std::max(max_reduction, 2);
            } else {
                max_reduction = std::max(max_reduction, 1);
            }
        }
    }

    // 3. Print minimal compressed length
    std::cout << base_len - max_reduction << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}