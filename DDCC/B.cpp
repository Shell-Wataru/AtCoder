#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long  N,answer,i,temp;
    cin >> N;
    answer = 1;

    if (N % 2 == 0){
        temp = N/2 - 1;
        answer = temp * (temp + 1) * 2;
    }else{
        temp = (N-3)/2;
        answer = temp * (temp - 1) * 2 + temp * 4 + 1;
    }
    cout << answer << endl;

    return 0;
}