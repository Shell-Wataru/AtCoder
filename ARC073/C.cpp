#include<iostream>
#include <algorithm>
#include <vector>
#include <deque> 
using namespace std;

long minValue(long H,long W){
    long minVal,i;
    if (W%3 == 0){
        minVal= 0;
    }else{
        minVal = H;
        long long min = H*W;
        for (i=1;i< W;i++){
            long min = max({abs(H*i- (W-i)*(H/2)),abs(H*i- (W-i)*(H/2 + H%2)),(W-i)*(H%2)});
            if (min == 32704){}
            if (min< minVal){
                minVal = min;
            }
        }
    }
    return minVal;
}

int main()
{
    // 整数の入力
    long H,W,i,a,b,candidate1,candidate2,candidate3;
    cin >> H >> W;
    cout << min(minValue(H,W),minValue(W,H)) <<endl;
    return 0;
}

