#include <iostream>

using namespace std;



void solve(){
    int size{};
    cin >> size;
    int idx = 1;

    while(size--){
        cout << idx << " ";
        idx += 2;
    }
    cout << endl;
}



int main(){
    int t{};
    cin >> t;
    while(t--) solve();

    return 0;
}