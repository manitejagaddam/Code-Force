#include <bits/stdc++.h>



void solve(int & num){
    std::string s;
    std::cin >> s;
    if(s[1] == '+') ++num;
    else --num;
}

int main(){
    int n;
    std::cin >> n;
    int num = 0;
    for(int i = 0 ; i < n ; i++) solve(num);
    std::cout << num;
    return 0;
}