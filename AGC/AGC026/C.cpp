#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    long long N,BLUE,RED,UNKNOWN,total_contents;
    RED = 1;
    BLUE = -1;
    UNKNOWN = 0;
    total_contents = 0;
    string S;
    cin >> N >> S;
    vector<vector<long long> >counts;
    counts.assign(26,vector<long long>());
    for (int i = 0;i<2 * N;i++){
        long long string_index = S[i] - 'a';
        counts[string_index].push_back(i);
    }
    vector<long long>colors;
    long long red_index = 0;
    long long red_decided_index = 0;
    long long blue_index = 2* N -1;

     // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<N); ++bit){
        vector<char> reds,blues;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                colors[i] = RED;
                reds.push_back(S[i]);
            }else{
                colors[i] = BLUE;
            }
        }
        for (int i = 0 ; i< N;i++){
            if (S[2 * N - 1 - i] == reds[i]){
                colors[2 * N - 1 - i] = BLUE;
            }else{
                colors[2 * N - 1 - i] = RED;
            }
        }
    }
    return 0;
}