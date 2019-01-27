#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;
long long base =  10000000007;

long long pow(long long n,long long i ){
    if (i == 0){
        return 1;
    }else{
        return n * pow(n ,i- 1) % base;
    }
    return
}

int main()
{
    // 整数の入力
    long long  N,answer,i,temp;
    long long kataho[10001];
    for (i = 1;i< 10001;i++){
        kataho[i] = pow(i, 10) - pow(i - 1, 10);
    }


    cin >> N;


    cout << answer << endl;

    return 0;
}