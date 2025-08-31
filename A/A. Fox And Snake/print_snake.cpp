#include <iostream>
#include <vector>



int main (){
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<char>> grid(m, std::vector<char>(n , '.'));
    bool first = false;
    for(int i = 0 ; i < m ; i++){
        if(i % 2 == 1){
            if(first) grid[i][0] = '#';
            else grid[i][n - 1] = '#';
            first = !first;
            continue;
        }
        for(int j = 0 ; j < n ; j++){
            grid[i][j] = '#';
        }
    }

    for(int row = 0 ; row < m ; row++){
        for(int col = 0 ; col < n ; col++){
            std::cout << grid[row][col];
        }
        std::cout << std::endl;
    }

    return 0;
}