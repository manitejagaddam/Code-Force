#include <iostream>

using namespace std;


bool isDivided(int n){
    if(n % 2 == 0 && n > 2) return true;
    return false;
}




int main(){

    int n;
    cin >> n;
    if(isDivided(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;

}