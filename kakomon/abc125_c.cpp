#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main()
{
    // 整数の入力
    ll N, M;
    cin >> N;
    vector<ll> A(N);
    vector<ll> forwardGCD(N+1,0);
    vector<ll> backwardGCD(N+1,0);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    for(int i = 0;i < N;i++){
        forwardGCD[i+1] = gcd(forwardGCD[i],A[i]);
    }
    for(int i = N-1;i >= 0;i--){
        backwardGCD[i] = gcd(backwardGCD[i+1],A[i]);
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        ans = max(ans,gcd(forwardGCD[i],backwardGCD[i+1]));
    }
    cout << ans << endl;
    return 0;
}