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

using namespace std;

long long N,M,K,i,j;
long long BASE_NUM = 1000000007;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

long long combination(long long n,long long m){
    long long value = 1;
    m = min(m,n-m);
    for (long long i = 0;i < m;i++){
        value = (value * (n - i)) % BASE_NUM;
    }

    for (long long i = 1;i <= m;i++){
        long long x,y,reverse;
        extGCD(i,BASE_NUM,x,y);
        reverse = (x + ((abs(x/BASE_NUM) + 1)* BASE_NUM) )% BASE_NUM;
        value = (value * reverse) % BASE_NUM;
    }
    return value;
}

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
    cin >> N >> M;
    map<long long,long long> primes;
    decomposite(abs(N),primes);
    long long first = 1;
    for (int i = 1;i<M;i++){
        first = (first<<1) % BASE_NUM;
    }
    for(auto itr = primes.begin(); itr != primes.end(); ++itr) {
        first = (first * combination(itr->second + M - 1 , M - 1)) % BASE_NUM;
    }
    cout << first << endl;
    return 0;
}