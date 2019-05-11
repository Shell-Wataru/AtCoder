#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;


int main()
{
    // 整数の入力
    long long N,t,v,d,nowV,i,j;
    vector<long long> Ts,Vs;
    cin >> N;
    nowV = 0;
    Ts.push_back(0);
    for (i= 0;i< N;i++){
        cin >>t;
        Ts.push_back(Ts.back() + t);
    }
    Ts.push_back(Ts.back());

    Vs.push_back(0);
    for (i= 0;i< N;i++){
        cin >>v;
        Vs.push_back(v);
    }
    Vs.push_back(0);

    for (i = 0;i< N;i++){
        long long minBreakingTime = Ts.back() + 1;
        long long minBreakingIndex = -1;
        for(j = i+1;j<N;j++){
            minBreakingTime = Ts[j] - Ts[i] - Vs[i];
        }
    }
    return 0;
}