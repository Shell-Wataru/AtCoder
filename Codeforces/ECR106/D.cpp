#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else{
        ll y_2 =my_pow(x,y/2);
        ll yy = y_2 * y_2;
        if (y % 2 == 0){
            return yy;
        }else{
            return yy * x;
        }
    }
}
vector<int> prime_numbers(int n){
    if (n <= 1){
        return vector<int>(0);
    }
    vector<int> ans = {2};
    for(int i = 3;i <= n;i++){
        bool is_prime = true;
        for(int j = 0; ans[j] * ans[j] <= i;j++){
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
vector<int> primes = prime_numbers(5001);
void decomposite(int N, map<int,int> &factors,int p_index = 0){
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
vector<ll> count_cache(20000001,0);
int count(int w){
  if (count_cache[w] != 0){
    return count_cache[w];
  }
  for(int i = 0;primes[i] * primes[i] <= w;i++){
    if (w % (primes[i]*primes[i]) == 0){
      count_cache[w] = count(w/primes[i]);
      return count_cache[w];
    }else if (w % primes[i] == 0){
      count_cache[w] = 2* count(w/primes[i]);
      return count_cache[w];
    }
  }
  count_cache[w] = 2;
  return count_cache[w];
}
void check(ll &ans, ll c, ll d, ll x, ll g)
{
  // cout << g << endl;
  if ( (x + d*g) % (c*g) == 0)
  {
    ll w = (x + d*g) / (c*g);
    // cout << w << " " << count(w) << endl;
    ans += count(w);
  }
}
int solve()
{
  ll c, d, x;
  scanf("%lld", &c);
  scanf("%lld", &d);
  scanf("%lld", &x);
  ll gcd_cd = gcd(c,d);
  if (x % gcd_cd != 0){
    cout << "0\n";
    return 0;
  }
  c /=  gcd_cd;
  d /= gcd_cd;
  x /= gcd_cd;
  ll ans = 0;
  map<int,int> x_factors;
  decomposite(x,x_factors);
  vector<pair<int,int>> x_factor_array(x_factors.begin(),x_factors.end());
  vector<ll> pow_maxs(x_factors.size(),0);
  vector<ll> current_factors(x_factors.size(),0);
  for(int i = 0;i < x_factors.size();i++){
    pow_maxs[i] = my_pow(x_factor_array[i].first,x_factor_array[i].second);
  }
  ll current = 1;
  bool is_end = false;
  while(!is_end){
    // cout << current << endl;
    check(ans, c, d, x, current);
    is_end = true;
    for(int i = 0;i < x_factor_array.size();i++){
      current_factors[i]++;
      if (current_factors[i] <= x_factor_array[i].second){
        current *= x_factor_array[i].first;
        is_end = false;
        break;
      }else{
        current_factors[i] = 0;
        current /=  pow_maxs[i];
      }
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  count_cache[1] = 1;
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}