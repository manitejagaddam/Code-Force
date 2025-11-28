#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    string s;
    cin >> s;

    long long fixed_sum = 0;
    int q_cnt = 0;
    for (char c : s) {
        if (c == 'X') fixed_sum += 10;
        else if (c == 'V') fixed_sum += 5;
        else if (c == 'I') fixed_sum += 1;
        else q_cnt++;
    }

    long long base_pairs = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'I') {
            if (s[i+1] == 'X' || s[i+1] == 'V') {
                base_pairs++;
            }
        }
    }

    long long sum_f0 = 0; 
    long long T_inc = 0;  
    long long T_flat = 0; 
    long long T_dec = 0;  

    for (int i = 0; i < n; ) {
        if (s[i] == '?') {
            int j = i;
            while (j < n && s[j] == '?') {
                j++;
            }
            int len = j - i;
            
            int S_I = 0; 
            if (i > 0 && s[i-1] == 'I') S_I = 1;
            
            int S_H = 0; 
            if (j < n && (s[j] == 'X' || s[j] == 'V')) S_H = 1;

            long long v0 = min((long long)S_I, (long long)len + S_H);
            long long ve = min((long long)len + S_I, (long long)S_H);
            long long vp = (len + S_I + S_H) / 2;

            sum_f0 += v0;
            
            long long inc = vp - v0;
            long long dec = vp - ve;
            long long flat = len - inc - dec;

            T_inc += inc;
            T_flat += flat;
            T_dec += dec;

            i = j;
        } else {
            i++;
        }
    }

    for (int k = 0; k < q; ++k) {
        long long cX, cV, cI;
        cin >> cX >> cV >> cI;

        long long use_I = min((long long)q_cnt, cI);
        long long rem = q_cnt - use_I;
        long long use_V = min(rem, cV);
        rem -= use_V;
        long long use_X = rem;

        long long current_sum = fixed_sum + use_I * 1 + use_V * 5 + use_X * 10;

        long long block_pairs = sum_f0;
        long long K = use_I;

        long long take = min(K, T_inc);
        block_pairs += take;
        K -= take;

        take = min(K, T_flat);
        K -= take;

        block_pairs -= K;

        long long total_pairs = base_pairs + block_pairs;
        
        cout << current_sum - 2 * total_pairs << "\n";
    }
}

int main() {
    int no_test_cases;
    cin >> no_test_cases;
    while (no_test_cases--) {
        solve();
    }
    return 0;
}