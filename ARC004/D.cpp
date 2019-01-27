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

map<long long,long long> decomposite(long long N, map<long long,long long> & primes,long long next_p = 2){
    if (N == 1){
        return primes;
    }


    while (next_p * next_p <= N ) {
        if (N % next_p == 0) {
            cout << next_p << endl;
            primes[next_p] += 1;
            return decomposite(N/next_p,primes,next_p);
        } else {
            next_p++;
        }
    }
    cout << N << endl;
    primes[N] += 1;
    return primes;
}

int main()
{
    // 整数の入力
    cin >> N >> M;
    map<long long,long long> primes;
    decomposite(N,primes);
    cout << "deconposited" <<endl;
    cout << primes.size() << endl;
    long long first = 1<<(M-1);
    cout  << first << endl;
    for(auto itr = primes.begin(); itr != primes.end(); ++itr) {
        first = (first * (itr->second + 1) ) % 1000000007;
    }
    cout << first << endl;
    return 0;
}