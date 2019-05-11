#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    int i,N,maxA,minA,a;
    int Count[9] = {0,0,0,0,0,0,0,0,0};
    minA = 0;
    cin >> N;
    for (i=0;i<N;i++){
        cin >> a;
        if (a < 400){
            Count[0] += 1;
        }else        if (a < 800){
            Count[1] += 1;
        }else        if (a < 1200){
            Count[2] += 1;
        }else        if (a < 1600){
            Count[3] += 1;
        }else        if (a < 2000){
            Count[4] += 1;
        }else        if (a < 2400){
            Count[5] += 1;
        }else        if (a < 2800){
            Count[6] += 1;
        }else        if (a < 3200){
            Count[7] += 1;
        }else{
            Count[8] += 1;
        }
    }
    for (i = 0; i<8;i++){
        if (Count[i] >0){
            minA += 1;
        }
    }
    if (minA == 0){
        cout << 1 << " "<< Count[8] <<endl;
    }else{
        cout << minA << " "<<  (minA + Count[8]) <<endl;
    }


    return 0;
}