#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll reverse(ll n,ll modulo){
    ll x,y;
    extGCD(n, modulo, x, y);
    return (x + ((abs(x / modulo) + 1) * modulo)) % modulo;
}

int main()
{
    // 整数の入力
    ll N;
    vector<ll> X;
    cin >> N;
    ll BASE = 1;
    for(int i = 1;i<=N-1;i++){
        BASE = BASE * i % BASE_NUM;
    }

    for(int i = 0;i<N;i++){
        ll x;
        cin >> x;
        X.push_back(x);
    }
    ll mean = 0;
    ll times = 0;

    for(int i = 0; i< N -1;i++){
        ll current_time = BASE * reverse(i+1,BASE_NUM) % BASE_NUM;
        times = (times + current_time) % BASE_NUM;
        ll current_mean = times * (X[i+1] - X[i]) % BASE_NUM;
        mean = (mean + current_mean) % BASE_NUM;
    }
    cout << mean << endl;
    return 0;
}