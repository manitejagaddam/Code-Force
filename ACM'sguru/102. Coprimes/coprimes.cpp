#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}