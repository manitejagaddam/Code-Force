#include <iostream>
#include <string>
using namespace std;


int main(){
    string s;
    cin >> s;

    int mpp[26];
    // initialising the array with 0
    for(int idx = 0 ; idx < 26 ; idx++) mpp[idx] = 0;

    // creating a frequency arrray
    for(char ch : s){
        mpp[ch - 'a']++;
    }

    int no_letters = 0;
    for(int idx = 0 ; idx < 26 ; idx++){
        if(mpp[idx] > 0) no_letters++;
    }

    if(no_letters % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
    cout << endl;

    return 0;

}