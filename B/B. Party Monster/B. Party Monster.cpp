#include <iostream>
using namespace std;



string solve(){
    int len{};
    cin >> len;
    string s {};
    cin >> s;
    int count {0};
    for(char ch : s){
        count += ch == '(' ? 1 : -1;
    }

    return count == 0 ? "YES" : "NO";
}


int main(){
    int t{};
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }

    return 0;
}