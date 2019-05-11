#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
using namespace std;

void addBIT(long long* BIT,int N,int index, long long v){
    int i;
    for(i = index;i < N;i+= i&-i) BIT[i] += v;
}

long long sumBIT(long long* BIT,int index){
    long long retValue = 0;
    int i;
    for(i = index;i > 0;i-= i& -i) retValue += BIT[i];
    return retValue;
}

int main()
{
    // 整数の入力
    long long i,j,N,K,temp,count,total,D,useQuantity;
    cin >> D;
    count = 0;
    if (D% 9 != 0){
        cout << 0 << endl;
    }else{
        string temp = to_string(D/9);
        vector<long long> remainCount;
        int zeroCount = 0;
        if (to_string(D).length() %2 == 0){
            count = 1;
        }else{
            count = 10;
        }
        for (i = temp.length() -1; i>= 0;i--){
            remainCount.push_back(temp[i] - '0');
            if (zeroCount == i && temp[i] == '0'){
                zeroCount += 1;
            }
        }
        for (i =0; i< zeroCount;i++){
            remainCount.push_back(0);
        }
        cout << temp << endl;
        for (i = 0;i< (remainCount.size()+1)/2 ;i++){
            if (remainCount[i] >= 0){
                useQuantity = remainCount[i];
            }else{
                useQuantity = (- remainCount[i]/10 + 1)*10 + remainCount[i];
            }
            cout << remainCount[i] << ":"<< useQuantity << endl;
            count *= 10 - abs(useQuantity) - (i==0);
            for (j = i; j< remainCount.size()-i;j++){
                remainCount[j] -= useQuantity;
                if (remainCount[j]/10 != 0){
                    remainCount[j+1] += remainCount[j]/10;
                    remainCount[j] = remainCount[j]%10;
                }
            }
        }

        for (i = 0;i< remainCount.size() ;i++){
            cout << remainCount[i] << endl;
        }

        cout << count << endl;
    }
    return 0;
}