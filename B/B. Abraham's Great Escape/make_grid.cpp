#include <iostream>
#include <vector>
using namespace std;


void solve() {
    int n;
    long long k;
    std::cin >> n >> k;

    long long total_cells = (long long)n * n;
    long long non_escape_cells = total_cells - k;

    
    if (non_escape_cells == 1) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::vector<std::vector<char>> grid(n, std::vector<char>(n, '.'));

    // 1. Place all k escape cells first.
    long long escapes_to_place = k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (escapes_to_place > 0) {
                grid[i][j] = 'U';
                escapes_to_place--;
            }
        }
    }

    // 2. Fill the remaining non-escape cells with loops.
    // If the number is odd, we make one 3-cell component first.
    if (non_escape_cells % 2 != 0) {
        bool found_start = false;
        for (int i = 0; i < n && !found_start; ++i) {
            for (int j = 0; j < n && !found_start; ++j) {
                if (grid[i][j] == '.') {
                    
                    if (j + 2 < n && grid[i][j + 1] == '.' && grid[i][j + 2] == '.') {
                        grid[i][j] = 'R';       
                        grid[i][j + 1] = 'R';   
                        grid[i][j + 2] = 'L';   
                        found_start = true;
                    } else if (i + 2 < n && grid[i+1][j] == '.' && grid[i+2][j] == '.') {
                        grid[i][j] = 'D';
                        grid[i+1][j] = 'D';
                        grid[i+2][j] = 'U';
                        found_start = true;
                    }
                }
            }
        }
    }
    
    // Fill the rest (which is now an even number) with 2-cell loops.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                if (j + 1 < n && grid[i][j + 1] == '.') {
                    grid[i][j] = 'R';
                    grid[i][j + 1] = 'L';
                } else if (i + 1 < n && grid[i + 1][j] == '.') {
                    grid[i][j] = 'D';
                    grid[i + 1][j] = 'U';
                }
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << grid[i][j];
        }
        std::cout << "\n";
    }
}


int main(){
    int no_test_cases;
    cin >> no_test_cases;
    while(no_test_cases--) solve();
    return 0;
}