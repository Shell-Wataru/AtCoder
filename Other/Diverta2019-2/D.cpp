#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

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

long long myPow(long long x, long long  n, long  long m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

int main()
{
    // 整数の入力
    long long N,counter;
    cin >>  N;
    long long i = 1;
    counter = 0;
    while (i < (N /i - 1)){
        // cout << i << endl;
        if (N % i == 0){
            counter +=  N/i - 1;
        }
        i++;
    }

    cout << counter << endl;
    return 0;
}