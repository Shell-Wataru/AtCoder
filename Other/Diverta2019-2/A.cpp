#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


int main()
{
    // 整数の入力
    int N,K;
    cin >> N >> K;
    if (K == 1){
        cout << 0 << endl;
    }else{
        cout << N - K << endl;
    }

    return 0;
}