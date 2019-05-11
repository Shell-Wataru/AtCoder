#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <bitset>

using namespace std;

long long pattern_mask = 0;
string pattern;

int main()
{
    // 整数の入力
    cin >> pattern;
    long long N = pattern.size();
    for(int i = 0; i< pattern.size();i++){
        if (pattern[i] == 'o'){
            pattern_mask |= 1<<i;
        }
    }
    // cout << bitset<10>(pattern_mask) << endl;

    long long min_tvs = 11;
    long long min_tv_pattern = 0;
    for (int i = 0; i < (1<<N);i++){
        long long current_pattern = 0;
        long long tvs = 0;
        for (int j = 0;j< N;j++){
            if (i & (1<<j)){
                current_pattern |= (pattern_mask << j) | (pattern_mask >> (N - j));
                tvs++;
            }
        }
        long long max_continue_count = 0;
        long long continue_count = 0;

        for (int j = 0;j< 2*N;j++){
            if (current_pattern & (1<<j)){
                continue_count++;
                max_continue_count = max(max_continue_count,continue_count);
            }else{
                continue_count = 0;
            }
        }
        if (max_continue_count >= N){
            min_tvs = min(tvs,min_tvs);
            if (min_tvs == tvs){
                min_tv_pattern = i;
            }
        }
    }
    cout << min_tvs << endl;
    // cout << bitset<10>(min_tv_pattern) << endl;
    return 0;
}