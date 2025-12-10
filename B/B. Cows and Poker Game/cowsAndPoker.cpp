#include <iostream>
#include <cstring>
using namespace std;


int main(){
    int len ;
    cin >> len;
    string s;
    cin >> s;
    bool foundI = false;
    int countA = 0;
    for(char ch : s){
        if(ch == 'I'){
            if(!foundI) foundI = true;
            else {
                cout << 0;
                return 0;
            } 
        }else if(ch == 'A') countA++;
    }
    if(foundI){
        cout << 1;
        return 0;
    }
    cout << countA;
    return 0;

}