#include <iostream>



int main(){
    int no_stops = 0;
    std::cin >> no_stops;
    int no_passengers = 0;
    int minSeats = 0;
    for(int stops = 0 ; stops < no_stops ; stops++){
        int entry, exit;
        std::cin >> exit >> entry;
        no_passengers -= exit;
        no_passengers += entry;
        minSeats = minSeats < no_passengers ? no_passengers : minSeats;
    }

    std::cout << minSeats;
    return 0;
}