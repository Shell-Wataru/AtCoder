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

const long long BASE_NUM = 1000000000000000009ll;

pair<ll,ll> one(ll m){
    return {(10 / m) % m, 10 % m};
}

pair<ll,ll> product(pair<ll,ll> &a,pair<ll,ll> &b, ll m){
    return {
        (a.first * b.second + a.second * b.first + a.second * b.second/m) % m,
        (a.second * b.second) % m
    };
}

pair<ll, ll> value(ll n, ll m)
{
    if (n == 1)
    {
        return one(m);
    }
    auto p = value(n / 2, m);
    auto pp = product(p,p,m);
    auto e = one(m);
    if (n % 2 == 1)
    {
        return product(pp,e,m);
    }
    else
    {
        return pp;
    }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    if (M == 1)
    {
        cout << 0 << endl;
    }else{
        cout << value(N, M).first << endl;
    }
    return 0;
}