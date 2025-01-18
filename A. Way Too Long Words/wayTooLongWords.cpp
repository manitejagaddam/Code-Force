#include <iostream>
#include <string>
#include <vector>

using namespace std;



string short_word(string s){
    int n = s.length();
    string ans = "";
    if(n > 10) {
        ans += s[0];
        ans += to_string(n - 2);
        ans += s[n - 1];
    }else return s;
    return ans;
}




int main(){

    int n;
    cin >> n;
    vector<string> questions;

    for (int i = 0 ; i < n  ; i++){
    string s;
    cin >> s;
    questions.push_back(s);

    }

    for(string s : questions){
        string ans = short_word(s);
        cout << ans << endl;
    }

}