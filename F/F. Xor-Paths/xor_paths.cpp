#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <tuple>
#include <functional>

using namespace std;

using ll = long long;


long long dfs(std::vector<std::vector<long long>> &grid, int row, int col, int m, int n, long long xor_val, long long target){
    if(row == m - 1 && col == n - 1){
        return (xor_val ^ grid[row][col]) == target ? 1 : 0;
    }
    if(row >= m || col >= n) return 0;

    long long temp_xor = xor_val ^ grid[row][col];

    return dfs(grid, row + 1, col, m, n, temp_xor, target) +
           dfs(grid, row, col + 1, m, n, temp_xor, target);
}


long long memoization(std::vector<std::vector<long long>> &grid, int row, int col, long long xor_val, long long target, std::map<std::tuple<long long,long long,long long>, long long> &dp){
    if(row == 0 && col == 0) 
        return (xor_val ^ grid[row][col]) == target ? 1 : 0;

    if(row < 0 || col < 0) return 0;

    auto key = std::make_tuple(row, col, xor_val);
    if(dp.find(key) != dp.end()) return dp[key];

    long long temp_xor = xor_val ^ grid[row][col];

    long long ans = memoization(grid, row - 1, col, temp_xor, target, dp) +
              memoization(grid, row, col - 1, temp_xor, target, dp);

    return dp[key] = ans;
}


long long tabulation(std::vector<std::vector<long long>> &grid, long long k) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::unordered_map<long long,long long>> prev(n), cur(n);

    prev[0][grid[0][0]] = 1; // base case

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::unordered_map<long long,long long> temp;

            if(i == 0 && j == 0){
                temp[grid[0][0]] = 1; // base case
            }
            else {
                if(i > 0){
                    for(auto &[xor_val, cnt] : prev[j])
                        temp[xor_val ^ grid[i][j]] += cnt;
                }
                if(j > 0){
                    for(auto &[xor_val, cnt] : cur[j-1])
                        temp[xor_val ^ grid[i][j]] += cnt;
                }
            }

            cur[j] = std::move(temp);
        }
        swap(prev, cur);
    }


    // for(int j = 0; j < n; j++){
    //     for(auto it : prev[j]){
    //         std::cout << it.first << " -> " << it.second << "   ";
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "------\n";

    return prev[n-1][k];
}





// Forward DFS: from (0,0) to mid-layer
void dfs_forward(vector<vector<ll>>& grid, int i, int j, ll xor_val, int steps, int half_steps,
                 vector<vector<unordered_map<ll,ll>>>& fmap) {
    xor_val ^= grid[i][j];
    if(steps == half_steps) {
        fmap[i][j][xor_val]++;
        return;
    }
    if(i+1 < grid.size()) dfs_forward(grid,i+1,j,xor_val,steps+1,half_steps,fmap);
    if(j+1 < grid[0].size()) dfs_forward(grid,i,j+1,xor_val,steps+1,half_steps,fmap);
}

// Backward DFS: from (n-1,m-1) to mid-layer
void dfs_backward(vector<vector<ll>>& grid, int i, int j, ll xor_val, int steps, int half_steps,
                  vector<vector<unordered_map<ll,ll>>>& bmap) {
    xor_val ^= grid[i][j];
    if(steps == half_steps) {
        bmap[i][j][xor_val]++;
        return;
    }
    if(i-1 >= 0) dfs_backward(grid,i-1,j,xor_val,steps+1,half_steps,bmap);
    if(j-1 >= 0) dfs_backward(grid,i,j-1,xor_val,steps+1,half_steps,bmap);
}

ll meet_in_middle(vector<vector<ll>>& grid, ll k) {
    int n = grid.size(), m = grid[0].size();
    int total_steps = n + m - 2;
    int half_steps = total_steps / 2;

    vector<vector<unordered_map<ll,ll>>> fmap(n, vector<unordered_map<ll,ll>>(m));
    vector<vector<unordered_map<ll,ll>>> bmap(n, vector<unordered_map<ll,ll>>(m));

    dfs_forward(grid,0,0,0,0,half_steps,fmap);
    dfs_backward(grid,n-1,m-1,0,0,total_steps-half_steps,bmap);

    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(fmap[i][j].empty() || bmap[i][j].empty()) continue;
            for(auto &f: fmap[i][j]){
                ll fxor = f.first;
                ll fcnt = f.second;
                ll required = fxor ^ k;
                if(bmap[i][j].count(required))
                    ans += fcnt * bmap[i][j][required];
            }
        }
    }
    return ans;
}




long long XorPaths(std::vector<std::vector<long long>> & grid, long long k){
    int m = grid.size();
    int n = grid[0].size();
    // return dfs(grid, 0, 0, m, n, 0LL, k);
    // std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, -1));
    // std::map<std::tuple<long long, long long, long long>, long long> dp;
    // return memoization(grid, m - 1, n - 1, 0LL, k, dp);

    // return tabulation(grid, k);
    return meet_in_middle(grid, k);

}


int main(){
    int m, n;
    long long k;
    std::cin >> m >> n >> k;
    std::vector<std::vector<long long>> grid(m, std::vector<long long>(n));

    for(int row = 0; row < m ; row++){
        for(int col = 0 ; col < n ; col++){
            std::cin >> grid[row][col];
        }
    }

    if(m == 1 && n == 1) {
        if(grid[0][0] == k) std::cout << 1;
        else std::cout << 0;
        return 0;
    } 

    long long ans = XorPaths(grid, k);

    std::cout << ans;
    return 0;

}