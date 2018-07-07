#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


int main()
{
    // 整数の入力
    string N;
    cin >> N;
    unsigned long maxSum = 0;
    for (int i=0;i< N.length();i++){
        maxSum += N[i] - '0';
    }
    maxSum = max(maxSum,(N.length() - 1) * 9 + (N[0] - '1')) ;

    cout << maxSum << endl;
    return 0;
}