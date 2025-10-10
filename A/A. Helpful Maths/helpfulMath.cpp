#include <iostream>
#include <string>
using namespace std;



int main(){
    string s;
    cin >> s;
    int count_1 = 0, count_2 = 0, count_3 = 0;
    int len = s.length();
    for(int idx = 0 ; idx < len ; idx += 2){
        s[idx] == '1' ? count_1++ : s[idx] == '2' ? count_2++ : count_3++;
    }

    int idx = 0;
    while(count_1--){
        s[idx] = '1';
        idx += 2;
    }

    while(count_2--){
        s[idx] = '2';
        idx += 2;
    }
    
    while(count_3--){
        s[idx] = '3';
        idx += 2;
    }

    cout << s;
    return 0;
}