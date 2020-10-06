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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;


//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
vector<ll> inverse_array(ll n){
    vector<ll> inverse(n,-1);
    inverse[1] = 1;
    for(int i = 2;i<n;i++){
        inverse[i] = BASE_NUM - inverse[BASE_NUM % i] * (BASE_NUM/i) % BASE_NUM;
    }
    return inverse;
}

ll combination(vector<ll> &factorial, vector<ll> &inverse_factorial, ll n,ll m){
    ll value = factorial[n];
    value = value * inverse_factorial[m] % BASE_NUM;
    value = value * inverse_factorial[n - m] % BASE_NUM;
    return value;
}

int main()
{
    // 整数の入力
    ll N,K;
    vector<ll> X;
    cin >> N >> K;
    vector<ll> inverse = inverse_array(N);
    vector<ll> factorial;
    factorial.push_back(1);
    for(int i = 1;i<= N;i++){
        factorial.push_back(factorial[i-1] * i % BASE_NUM);
    }

    vector<ll> inverse_factorial;
    inverse_factorial.push_back(1);
    for(int i = 1;i<= N;i++){
        inverse_factorial.push_back(inverse_factorial[i-1] * inverse[i] % BASE_NUM);
    }
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        X.push_back(x);
    }
    sort(X.begin(),X.end());
    ll max_sum = 0;
    ll min_sum = 0;
    for(int i = 1;N - i >= K - 1;i++){
        // cout << i << endl;
        ll current = (BASE_NUM + X[N - i]) % BASE_NUM;
        ll add = combination(factorial,inverse_factorial,N - i, K - 1) * current % BASE_NUM;
        max_sum = (max_sum + add) % BASE_NUM;
    }
    // cout << max_sum << endl;

    for(int i = 1;N - i >= K - 1;i++){
        ll current = (BASE_NUM + X[i - 1]) % BASE_NUM;
        ll add= combination(factorial,inverse_factorial,N - i, K - 1) * current % BASE_NUM;
        min_sum = (min_sum + add) % BASE_NUM;
    }
    // cout << min_sum << endl;
    // cout << combination(factorial, inverse_factorial,4,4) << endl;

    cout << ( BASE_NUM  + max_sum - min_sum) % BASE_NUM << endl;;
    return 0;
}