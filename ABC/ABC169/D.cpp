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
namespace mp = boost::multiprecision;

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

int can_use(ll N,ll l,ll r){
    if (l+ 1  == r){
        return l;
    }
    ll center = (l+r)/2;
    if(center * (center + 1)/2 <= N){
        return can_use(N, center,r);
    }else{
        return can_use(N, l,center);
    }
}
int main()
{
  // 整数の入力
  ll N,M;
  cin >> N;
  map<ll,ll> primes;
  decomposite(N,primes);
  ll ans = 0;
  for(auto p:primes){
      ans += can_use(p.second,0,1e9);
  }
  cout << ans << endl;
  return 0;
}