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

long long gcd(long long a, long long b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }

    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    map<ll,ll> counts;
    for (size_t i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        counts[a]++;
    }
    for(int i = 0;i< M;i++){
        ll a,b;
        cin >> a >> b;
        auto p = *counts.begin();
        while(a > 0 && counts.begin()->first < b){
            if (a >= counts.begin()->second){
                counts[b] +=counts.begin()->second;
                a = a - counts.begin()->second;
                counts.erase(counts.begin()->first);
            }else{
                counts[b] += a;
                counts[counts.begin()->first] -=  a;
                a = 0;
            }
        }
    }
    ll ans = 0;
    for(auto p:counts){
        ans += p.first * p.second;
    }
    cout << ans << endl;
    return 0;
}