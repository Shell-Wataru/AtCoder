#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;
int main()
{
    // 整数の入力
    long long N,maxD,sumD,d;
    cin >> N;
    maxD = 0;
    sumD = 0;
    for (int i = 0;i< N;i++){
        cin >> d;
        sumD += d;
        if (d > maxD){
            maxD = d;
        }
    }

    cout << sumD << endl;
    if (2 * maxD > sumD){
        cout << 2 * maxD -  sumD;
    }else{
        cout << 0 << endl;
    }

    return 0;
}