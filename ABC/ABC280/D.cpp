#define _USE_MATH_DEFINES
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
#include <unordered_set>
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll counts(ll base,ll target, ll l,ll r){
  if (l+1 == r){
    return r;
  }
  // cout << l << "~" << r << endl;
  ll center = (l+r)/2;
  ll current = center;
  ll c = 0;
  while(current){
    c += current/base;
    current /= base;
  }
  // cout << base << "," << center << "=" << c << endl;
  if (c < target){
    return counts(base,target,center,r);
  }else{
    return counts(base,target,l,center);
  }
}

vector<ll> prime_numbers(ll n){
    if (n <= 1){
        return vector<ll>(0);
    }
    vector<ll> ans = {2};
    for(ll i = 3;i <= n;i++){
        bool is_prime = true;
        for(ll j = 0; ans[j] * ans[j] <= i;j++){
            if (i % ans[j] == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<ll> primes = prime_numbers(2000001);
void decomposite(ll N, map<ll,ll> &factors,ll p_index = 0){
    if (N == 1){
        return;
    }

    while (primes[p_index] * primes[p_index] <= N ) {
        if (N % primes[p_index] == 0) {
            factors[primes[p_index]] += 1;
            decomposite(N/primes[p_index],factors,p_index);
            return;
        } else {
            p_index++;
        }
    }
    factors[N] += 1;
}


int main()
{
  ll K;
  cin >> K;
  map<ll,ll> dec;
  decomposite(K,dec);
  ll ans = 0;
  for(auto p:dec){
    ans = max(ans,counts(p.first,p.second,0,K+1));
  }
  cout << ans << endl;
  // for(int i = 2;i<1000000;i++){
  // map<ll,ll> dec1;
  // decomposite(i,dec1);
  // ll ans = 0;
  // for(auto p:dec1){
  //   ans = max(ans,counts(p.first,p.second,0ll,1000000000000ll));
  // }
  // }
  return 0;
}