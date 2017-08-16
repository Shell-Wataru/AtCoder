#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


int main()
{
    // 整数の入力
    long long N,M,i,j;
    cin >> N>>M;
    vector<vector<int>> candidates;
    candidates.resize(N);

    for (i=0; i<N;i++){
        candidates[i].resize(0);
        if (i==0){
            candidates[i].push_back(1);
        }else{
            candidates[i].push_back(1);
            candidates[i].push_back(2);
            candidates[i].push_back(3);
        }
    }

    for (i=0; i<M;i++){
        candidates[i].resize(0);
        if (i==0){
            candidates[i].push_back(1);
        }else{
            candidates[i].push_back(1);
            candidates[i].push_back(2);
            candidates[i].push_back(3);
        }
    }
    return 0;
}
