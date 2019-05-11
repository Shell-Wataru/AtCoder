#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}


int main()
{
    // 整数の入力
    long long  N,M,i,max,core;
    string S,T;
    cin >> N >> M;
    cin >> S >> T;
    core = gcd(N,M);
    max = N*M /core;
    ll Ndiff = max/N;
    ll Mdiff = max/M;
    ll Xdiff = max/core;

    for(i = 0;i < max;i = i+ Xdiff ){
        if (S[i/Ndiff] != T[i/Mdiff]){
            max = -1;
        }
    }
    cout << max << endl;


    return 0;
}