#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,K,i;
    cin >> K;
    N = 50;
    cout << N << endl;
    long long base = K/50;
    long long amari = K % 50;
    for (i= 0; i< N;i++){
        if (i != 0){
            cout << " ";
        }
        if (i < amari){
            cout << N - i + base;
        }else{
            cout << N - i + base - 1;
        }
    }
    cout << endl;
    return 0;
}