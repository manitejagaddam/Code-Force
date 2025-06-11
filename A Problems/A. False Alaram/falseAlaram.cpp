#include <bits/stdc++.h>
using namespace std;

bool canPassThrough(vector<int> & doors, int off_sec){
    int start_alarm;
    int end_alarm;
    int noe = doors.size();
    for(int idx = 0 ; idx < noe ; idx++){
        if(doors[idx] == 1){
            start_alarm = idx;
            break;
        }
    }

    for(int idx = noe - 1 ; idx >= 0 ; idx--){
        if(doors[idx] == 1){
            end_alarm = idx;
            break;
        }
    }

    return end_alarm - start_alarm <= off_sec - 1;
}


void solve(){
    int noe; // no of elements
    int off_sec;
    cin >> noe;
    cin >> off_sec;
    vector<int> doors(noe);
    for(int idx = 0 ; idx < noe ; idx++) cin >> doors[idx] ;
    
    if(canPassThrough(doors, off_sec)) cout << "YES";
    else cout << "NO";
    cout << endl;
    return;
}

int main(){
    int notc; //no of test cases
    cin >> notc;
    for(int test_case = 0 ; test_case < notc ; test_case++){        
        solve();
    }
    return 0;
}
// 7
// 4 2
// 0 1 1 0
// 6 3
// 1 0 1 1 0 0
// 8 8
// 1 1 1 0 0 1 1 1
// 1 2
// 1
// 5 1
// 1 0 1 0 1
// 7 4
// 0 0 0 1 1 0 1
// 10 3
// 0 1 0 0 1 0 0 1 0 0
