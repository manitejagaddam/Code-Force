#include <iostream>
#include <vector>

using namespace std;



void solve(){
    int n;
    cin >> n;
    int mini = 1;
    int maxi = 3 * n;
    vector<int> ans;
    for(int idx = 0 ; idx < n ; idx++){
        ans.push_back(maxi--);
        ans.push_back(maxi--);
        ans.push_back(mini++);
    }

    for(int ele : ans) cout << ele << " ";
    cout << endl;
}



int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}