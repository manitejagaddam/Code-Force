#include <iostream>
using namespace std;



int getSmallestPrime(long long n){
    if(n % 2 == 0) return 2;

    for(long long idx = 3 ; idx * idx <= n ; idx += 2){
        if(n % idx == 0) return idx;
    }
    return n;
}


int main(){
    long long n;
    cin >> n;

    long long count = 0;
    long long current_pebbels = n;

    while(current_pebbels > 1){
        count += current_pebbels;

        long long smallestPrime = getSmallestPrime(current_pebbels);

        current_pebbels /= smallestPrime;
    }

    count++;
    cout << count;
    return 0;
}