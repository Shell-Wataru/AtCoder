#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;

long long N,temp;
vector<long long> weights;

int rm_decreasing_series(){
    long long bottom_weight = weights.front();
    long long index = 0;
    weights.erase(weights.begin());

    // cout << bottom_weight << ",";
    while(index < weights.size()){
        if (weights[index] <= bottom_weight){
            bottom_weight = weights[index];
            // cout << bottom_weight << ",";
            weights.erase(weights.begin() + index);
        }else{
            index++;
        }
    }
    // cout << endl;
    return 0;
}

int main()
{
    // 整数の入力
    cin >> N;

    for (int i = 0; i < N;i++){
        cin >> temp;
        weights.push_back(temp);
    }
    // cout << "--" << endl;

    long long yama = 0;
    while(!weights.empty()){
        rm_decreasing_series();
        yama++;
    }
    // cout << "--" << endl;

    cout << yama << endl;
    return 0;
}