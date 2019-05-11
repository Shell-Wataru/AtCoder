#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

long long permutation(int N){
    if (N==1){
        return 1;
    }else{
        return N * permutation(N-1) % 1000000007;
    }
}

int main()
{
    // 整数の入力
    long long total,N,M;
    cin >> N >> M;
    if (abs(N - M) > 1){
        cout << 0 << endl;
    }else if(N == M){
        cout << (2 * permutation(N)* permutation(M)) % 1000000007<< endl;
    }else{
        cout << (permutation(N)* permutation(M)) % 1000000007<< endl;
    }
    return 0;
}