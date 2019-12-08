#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;
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

ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else if(y == 1){
        return x;
    }else{
        ll y_2 =my_pow(x,y/2) % BASE_NUM;
        ll yy = (y_2 * y_2) % BASE_NUM;
        if (y % 2 == 0){
            return yy;
        }else{
            return (yy * x) % BASE_NUM;
        }
    }
}
int main()
{
    // 整数の入力
    ll x,n;
    cin >> x >> n;
    map<ll,ll> dec;
    decomposite(x,dec);
    ll total = 1;
    for(auto p:dec){
        ll prime = p.first;
        // cout << prime << endl;
        ll current = n;
        ll current_total = 0;
        while(current > 0){
            // cout << current << endl;
            current = current/prime;
            current_total += current;
        }
        total = total * my_pow(prime,current_total) % BASE_NUM;

    }
    cout << total << endl;
    return 0;
}
