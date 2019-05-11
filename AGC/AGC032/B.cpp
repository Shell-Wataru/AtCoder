#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;


int main()
{
    // 整数の入力
    long long N;
    cin >> N;
    long long M = N - (N % 2);
    if (N % 2 == 0){

    }
    for (int i = 1;i<=N/2;i++){
        for (int j = i + 1;j<=N/2;j++){
            cout << i << " " << j << endl;
            cout << i << " " << M + 1 -j  << endl;
            cout << M + 1- i << " " << j << endl;
            cout << M + 1 - i << " " << M + 1 - j  << endl;
        }
    }

    if (N % 2 == 1){
        for (int i = 1;i < N;i++){
            cout << i << " " << N << endl;
        }
    }
    return 0;
}