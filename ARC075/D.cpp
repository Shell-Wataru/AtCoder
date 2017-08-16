#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

bool isAllDead(long long attacks,long long A,long long B,vector<long long> hitpoints){
    long long i,ACount = 0;
    for (i=0;i<hitpoints.size();i++){
        long long hitpoint = hitpoints[i] - attacks * B;
        if (hitpoint > 0){
            ACount += hitpoint / (A - B) + (hitpoint % (A - B) != 0);
        }
    }
    return ACount <= attacks;
}

int main()
{
    // 整数の入力
    long long i,N,A,B,temp,upper,lower;
    upper = 1000000001;
    lower = 0;
    vector<long long> hitpoints;
    cin >> N >> A >> B;

    for (i=0;i<N;i++){
        cin >> temp;
        hitpoints.push_back(temp);
    }


    while (lower != (upper + lower)/2){
        if (isAllDead((upper + lower)/2,A,B,hitpoints)){
            upper = (upper + lower)/2;
        }else{
            lower = (upper + lower)/2;
        }
    }
    cout << upper << endl;
    return 0;
}