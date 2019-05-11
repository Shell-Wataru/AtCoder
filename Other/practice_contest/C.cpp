#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

long long gcd(long long a, long long b){
    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main()
{
    // 整数の入力
    long long N,ai,i,T;
    cin >> N;
    for (i= 0;i<N;i++){
        cin >> ai;
        if (i ==0 ){
            T = ai;
        }else{
            T = ai* (T / gcd(T,ai));
        }
    }

    cout << T<< endl;
    return 0;
}