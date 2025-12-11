#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



/*

    n ingrediants
    one cokkie all n ingrediants

    k magic powder

    b has 

    a required



*/


bool isPossible(vector<int> a, vector<int> b, int k, int req){
    int len = a.size();
    for(int idx = 0 ; idx < len ; idx++){
        int tempVal = b[idx];
        if((tempVal / a[idx]) < req){
            int reqVal = (a[idx] * req) - b[idx];
            // cout << a[idx] * req << " " << b[idx] << " " << req << " " << k << " " << endl;
            k -= reqVal;
            if(k < 0) return false;
        }
    }
    return k >= 0;
}


int solve(vector<int> a, vector<int> b, int k){

    int len = a.size();

    int maxi = 0;
    for(int idx = 0 ; idx < len ; idx++){
        int tempVal = (b[idx] + k) / a[idx];
        maxi = maxi < tempVal ? tempVal : maxi;
    }

    int start = 0;
    int end = maxi;
    int ans = 0;

    while(start <= end){
        int mid = (end + start) / 2;

        if(isPossible(a, b, k, mid)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return ans;

}




int main(){
    int len, k;
    cin >> len >> k;
    vector<int> a(len), b(len);
    for(int idx = 0 ; idx < len ; idx++) cin >> a[idx];
    for(int idx = 0 ; idx < len ; idx++) cin >> b[idx];

    cout << solve(a, b, k);

    return 0;
}