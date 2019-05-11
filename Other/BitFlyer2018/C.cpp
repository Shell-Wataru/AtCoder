#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;
bool clearnCondition(vector<long long> X,long long D,long long  i,long long j,long long k){
    return X[j]- X[i] <= D && X[k] - X[j] <= D && X[k] - X[i] > D;
}

int clearIndex(vector<long long> X,long long D,long long  i,long long j,long long clearK,long long notClearK){
    if (clearK + 1== notClearK){
        return clearK;
    }
    long long newK = (clearK + notClearK)/2;

    if (clearnCondition(X,D,i,j,newK)){
        return clearIndex(X,D,i,j,newK,notClearK);
    }else{
        return clearIndex(X,D,i,j,clearK,newK);
    }
}

int main()
{
    // 整数の入力
    long long  N,D,x_i,result,i,j,k;
    cin >> N >> D;
    vector<long long> X;

    for (i = 0;i< N;i++){
        cin >> x_i;
        X.push_back(x_i);
    }

    result = 0;
    for(i=0;i<N-2;i++){
        if (X[N-1] - X[i] <= D){
            break;
        }
        for (j=i+1;j<N-1;j++){
            if (X[i] - X[j] > D && X[N-1] - X[j] <= D){
                break;
            }
            result += clearIndex(X,D,i,j,j,N) - j;
        }
    }

    cout << result << endl;

    return 0;
}