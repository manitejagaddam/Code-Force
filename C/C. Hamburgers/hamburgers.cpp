#include <iostream>
#include <string>


int main(){
    std::string s;
    std::cin >> s;
    int nb, ns, nc;
    std::cin >> nb >> ns >> nc;
    int pb, ps, pc;
    std::cin >> pb >> ps >> pc;

    long long amount;
    std::cin >> amount;

    int needB = 0;
    int needS = 0;
    int needC = 0;
    for(char ch : s){
        if (ch == 'B') needB++;
        else if(ch == 'S') needS++;
        else if(ch == 'C') needC++;
    }


    long long left = 0;
    long long right = 1e13;

    long long ans = 0;

    while(left <= right){
        long long mid = (left + right) / 2;

        long long buyB = std::max(0LL, needB * mid - nb);
        long long buyS = std::max(0LL, needS * mid - ns);
        long long buyC = std::max(0LL, needC * mid - nc);

        long long cost = buyB * pb + buyC * pc + buyS * ps;

        if(cost <= amount){
            ans = mid;
            left = mid + 1;
        }else right = mid - 1;
    }

    std::cout << ans;
    return 0;
}