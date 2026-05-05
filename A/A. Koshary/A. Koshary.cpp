#include <iostream>
using namespace std;



int main(){
    int n{};
    cin >> n;
    while(n--){
        int endX{}, endY{};
        cin >> endX >> endY;
        if(endX % 2 == 1 && endY % 2 == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}