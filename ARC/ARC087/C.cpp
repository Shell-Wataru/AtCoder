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
    long long  N,K,i,a_i,result,temp;
    cin >> N;
    long long* number1 = new long long[N+1];
    long long* number2 = new long long[N+1];
    number1[0] = 0;
    number2[0] = 0;
    for (i = 1;i<= N;i++){
        cin >> temp;
        number1[i] = number1[i-1] + temp;
    }

    for (i = 1;i<= N;i++){
        cin >> temp;
        number2[i] = max(number1[i] + temp,number2[i-1] + temp);
    }

    cout << number2[N] << endl;

    return 0;
}