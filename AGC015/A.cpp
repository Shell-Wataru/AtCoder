#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    long long  N,A,B,total;
    cin >> N >> A >>B;

    if ((A < B && N > 1) || A == B){
        cout << (B - A) * (N-2) + 1 << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}