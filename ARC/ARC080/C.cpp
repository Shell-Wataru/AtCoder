#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,ai,i,fourCount,twoCount,oneCount;
    oneCount = 0;
    twoCount = 0;
    fourCount = 0;
    cin >> N;
    for (i= 0;i<N;i++){
        cin >> ai;
        if (ai % 4 == 0){
            fourCount++;
        }else if(ai % 2 == 0){
            twoCount++;
        }else{
            oneCount++;
        }
    }

    if((twoCount == 0 && fourCount >= oneCount - 1) || (twoCount > 0 && fourCount >= oneCount)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    return 0;
}