#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

ll getN(double mean){
    return 2 * mean + 1;
}

bool isClear(ll N,ll M,ll X,ll Y){
    ll pureX = N* N + N - 2 * M;
    ll pureY = 2 * N;
    ll pure_core = gcd(pureX,pureY);
    ll core = gcd(X,Y);
    return (pureX/pure_core == X/core) && (pureY/pure_core == Y/core);
}

bool outputIfClear(ll N,ll X,ll Y){
    if (N <= 0){
        return false;
    }
    ll coreYN = gcd(Y,N);
    ll tempY = Y/coreYN;
    ll tempN = N/coreYN;
    ll coreYX= gcd(tempY,X);
    tempY = tempY/coreYX;
    ll tempX = X/coreYX;

    // cout << N << endl;
    // cout << tempY << endl;

    ll M = (N * N + N - 2 * tempX * tempN/tempY)/2;
    if (tempY == 1 && M >= 1 && M <= N){
        cout << N << " " << M <<endl;
        return true;
    }else{
        return false;
    }
}

int main()
{
    // 整数の入力
    ll N1,M1,N2,M2,X,Y;
    double mean;
    char sep;
    cin >> X >> sep >>Y;

    mean = X*1.0/Y;
    N1 = 2 * mean + 1;
    N2 = 2 * mean;

    bool n2Clear = outputIfClear(N2,X,Y);
    bool n1Clear = outputIfClear(N1,X,Y);

    if (!n1Clear && !n2Clear){
        cout << "Impossible" << endl;
    }

    return 0;
}