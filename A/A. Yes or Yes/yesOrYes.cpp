#include <iostream>
#include <cstring>
using namespace std;

string solve(){
    string s;
    cin >> s;
    int y_count = 0;
    for(char ch : s){
        if(ch == 'Y') y_count++;
    }

    return y_count <= 1 ? "YES" : "NO";
}

int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--){
        cout << solve() << endl;
    }
    return 0;
}