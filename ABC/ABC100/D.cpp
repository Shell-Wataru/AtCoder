#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <queue>

using namespace std;

long long maxPoint(long long N,long long M,long long r1,long long r2,long long r3,vector<long long>X,vector<long long>Y,vector<long long>Z){
    long long* maxPoints = new long long[N+1];
    for (int i = 1;i<= N;i++){
        for (int j = i;j>0;j--){
            if (j ==i){
                maxPoints[j] = maxPoints[j-1]+ r1 * X[i-1]+ r2 * Y[i-1]+ r3 *Z[i-1];
            }else{
                maxPoints[j] = max(maxPoints[j],maxPoints[j-1]+ r1 * X[i-1]+ r2 * Y[i-1]+ r3 *Z[i-1]);
            }
        }
    }
    return maxPoints[M];
}

int main()
{
        // 整数の入力
    long long N,M,xi,yi,zi;
    cin >> N>> M;
    vector<long long> X,Y,Z;
    long long* maxPoints = new long long[N+1];
    maxPoints[0] = 0;
    for (int i = 1;i<= N;i++){
        cin >> xi >> yi >> zi;
        X.push_back(xi);
        Y.push_back(yi);
        Z.push_back(zi);
    }
    long long real_max =maxPoint(N,M,1,1,1,X,Y,Z);
    long long temp = maxPoint(N,M,1,1,-1,X,Y,Z);
    if (real_max < temp){
        real_max = temp;
    }
    temp = maxPoint(N,M,1,-1,1,X,Y,Z);
    if (real_max < temp){
        real_max = temp;
    }

    temp = maxPoint(N,M,1,-1,-1,X,Y,Z);
    if (real_max < temp){
        real_max = temp;
    }

    temp = maxPoint(N,M,-1,1,1,X,Y,Z);
    if (real_max < temp){
        real_max = temp;
    }

    temp = maxPoint(N,M,-1,1,-1,X,Y,Z);
    if (real_max < temp){
        real_max = temp;
    }

    temp = maxPoint(N,M,-1,-1,1,X,Y,Z);
    if (real_max < temp){
        real_max = temp;
    }

    temp = maxPoint(N,M,-1,-1,-1,X,Y,Z);
    if (real_max < temp){
        real_max = temp;
    }

    cout << real_max << endl;

    return 0;
}