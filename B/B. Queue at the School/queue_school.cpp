#include <bits/stdc++.h>


void findPosition(std::string &s, int t){
    int len = s.length();
    for(int time = 0 ; time < t ; time++){
        bool swapped = false;
        for(int i = 0 ; i < len ; i++){
            if(i < len - 1 && s[i] == 'B' && s[i + 1] == 'G'){
                std::swap(s[i], s[i + 1]);
                i++;
                swapped = true;
            }
        }
        // std::cout << s << std::endl;
        if(!swapped) return;
    }
}

int main(){
    int n, t;
    std::cin >> n >> t;
    std::string s;
    std::cin >> s;

    findPosition(s, t);

    std::cout << s;

    return 0;
}