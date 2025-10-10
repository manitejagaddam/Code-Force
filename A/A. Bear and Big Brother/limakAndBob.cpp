#include <iostream>
#include <cmath>
using namespace std;



int main(){
    int a, b;
    cin >> a >> b;
    int count = 0;
//     while(a <= b){
//         a = a * 3;
//         b = b * 2;
//         count++;
//     }


    count = ceil(log((double)b / (double)a) / log(3.0 / 2.0)) + 1;

    cout << count << endl;
    return 0;

}