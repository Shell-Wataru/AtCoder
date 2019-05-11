#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int main()
{
    // 整数の入力
    long long N,ai,i,bar1,bar2;
    map<long long,long long> numCount;
    bar1 = 0;
    bar2 = 0;
    cin >> N;
    for (i= 0;i<N;i++){
        cin >> ai;
        if (numCount.count(ai) > 0){
            numCount[ai] += 1;
        }else{
            numCount[ai] = 1;
        }
        if (numCount.count(ai+1) > 0){
            numCount[ai+1] += 1;
        }else{
            numCount[ai+1] = 1;
        }
        if (numCount.count(ai-1) > 0){
            numCount[ai-1] += 1;
        }else{
            numCount[ai-1] = 1;
        }
    }
    int max = 0;
    for(auto itr = numCount.begin(); itr != numCount.end(); ++itr) {
        if (itr->second > max){
            max = itr->second;
        }
    }
    cout << max << endl;
    return 0;
}