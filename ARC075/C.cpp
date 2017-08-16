#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    long long total,i,N,minVal,temp;
    cin >> N;
    total = 0;
    minVal = 101;
    for (i=0;i<N;i++){
        cin >> temp;
        total += temp;
        if (temp % 10 != 0 && temp < minVal ){
            minVal = temp;
        }
    }
    if (total % 10 == 0){
        if (minVal == 101){
            cout << 0 << endl;
        }else{
            cout << total - minVal << endl;
        }
    }else{
        cout << total << endl;
    }
    return 0;
}