#include <iostream>
using namespace std;



int solve(){
    int no_teams;
    cin >> no_teams;
    return (no_teams - 1) * 2;
}

int main(){
    int no_test_cases;
    cin >> no_test_cases;

    while(no_test_cases--) cout << solve() << endl;

    return 0;
}