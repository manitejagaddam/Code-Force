#include <iostream>
#include <cstring>
using namespace std;


int solve(){
    int len, k;
    cin >> len >> k;
    string s;
    cin >> s;
    int ans = 0;
    int cooldownUntil = -1;
    for(int idx = 0 ; idx < len ; idx++){
        if(s[idx] == '0'){
            if(idx > cooldownUntil) ans++;
        }
        else if(s[idx] == '1') {
            cooldownUntil = idx + k;
        }
    }
    return ans;
}

int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--) cout << solve() << endl;
    return 0;
}