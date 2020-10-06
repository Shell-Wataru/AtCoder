#include<iostream>
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
namespace mp = boost::multiprecision;
ll BASE_NUM =  1000000007;

map<long long,long long> decomposite(long long N, map<long long,long long> & primes,long long next_p = 2){
    if (N == 1){
        return primes;
    }


    while (next_p * next_p <= N ) {
        if (N % next_p == 0) {
            primes[next_p] += 1;
            return decomposite(N/next_p,primes,next_p);
        } else {
            next_p++;
        }
    }
    primes[N] += 1;
    return primes;
}

int main()
{
    // 整数の入力
    bool is_p = false;
    ll X;
    cin >> X;
    while(!is_p){
        map<ll,ll> deco;
        decomposite(X,deco);
        if (deco.size() == 1 && (*deco.begin()).second == 1){
            is_p = true;
        }else{
            X++;
        }
    }
    cout << X << endl;
    return 0;
}