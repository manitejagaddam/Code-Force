#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int len;
long long k;
vector<int> nums;
vector<int> best_sol;
vector<int> current_sol;
vector<bool> is_candidate;
vector<int> cover_counts;

int get_index(int val){
    auto it = lower_bound(nums.begin(), nums.end(), val);
    if (it != nums.end() && *it == val){
        return distance(nums.begin(), it);
    }
    return -1;
}

void backtrack(int idx){
    while (idx < len && cover_counts[idx] > 0){
        idx++;
    }

    if (idx == len){
        if (best_sol.empty() || current_sol.size() < best_sol.size()){
            best_sol = current_sol;
        }
        return;
    }

    if (!best_sol.empty() && current_sol.size() >= best_sol.size()){
        return;
    }

    int target = nums[idx];

    vector<int> divisors;
    for (int i = 1; i * i <= target; ++i){
        if (target % i == 0){
            int pos = get_index(i);
            if (pos != -1 && is_candidate[pos]){
                divisors.push_back(i);
            }
            if (i * i != target){
                int d2 = target / i;
                int pos2 = get_index(d2);
                if (pos2 != -1 && is_candidate[pos2]){
                    divisors.push_back(d2);
                }
            }
        }
    }

    sort(divisors.rbegin(), divisors.rend());

    for (int d : divisors){
        current_sol.push_back(d);

        vector<int> affected_indices;
        for (long long m = d; m <= k; m += d){
            int pos = get_index((int)m);
            if (pos != -1){
                cover_counts[pos]++;
                affected_indices.push_back(pos);
            }
            else
            {
                break;
            }
        }

        backtrack(idx + 1);

        for (int pos : affected_indices){
            cover_counts[pos]--;
        }
        current_sol.pop_back();
    }
}

void solve(){
    cin >> len >> k;
    nums.resize(len);
    for (int i = 0; i < len; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    len = nums.size();

    is_candidate.assign(len, false);
    cover_counts.assign(len, 0);
    best_sol.clear();
    current_sol.clear();

    for (int i = 0; i < len; i++){
        long long val = nums[i];
        bool ok = true;
        int count = 0;

        for (long long m = val; m <= k; m += val){
            count++;
            if (count > len){
                ok = false;
                break;
            }
            if (get_index((int)m) == -1){
                ok = false;
                break;
            }
        }
        is_candidate[i] = ok;
    }

    backtrack(0);

    if (best_sol.empty()){
        cout << -1 << endl;
    }
    else
    {
        cout << best_sol.size() << endl;
        for (int i = 0; i < best_sol.size(); i++){
            cout << best_sol[i] << (i == best_sol.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main(){
    int t;
    if (cin >> t){
        while (t--){
            solve();
        }
    }
    return 0;
}