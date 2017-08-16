#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

long lowestCommon(long long n,long long m){
    if (n >= m){
        if (n % m == 0){
            return m;
        }else{
            return lowestCommon(m,n % m);
        }
    }else{
        return lowestCommon(m,n);
    }
}

int main()
{
    // 整数の入力
    long long N,K,lc,temp,i;
    vector<long long> A;
    cin >> N >> K;
    cin >> lc;
    A.push_back(lc);
    for (i=0;i<N-1;i++){
        cin >> temp;
        A.push_back(temp);
        lc = lowestCommon(lc,temp);
    }


    for (i=0;i<N;i++){
        if (A[i]== K || ( A[i] > K && ((A[i] - K) % lc) == 0 )){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}