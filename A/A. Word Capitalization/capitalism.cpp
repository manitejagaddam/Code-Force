#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int len = s.length();
    if(s[0] > 'Z') s[0] -= 'a' - 'A';  


    for(int idx = 1 ; idx < len ; idx++){
        if(s[idx - 1] == ' ' && s[idx] > 'Z') s[idx] -= 'a' - 'A';  
    }
    cout << s;
    return 0;
}