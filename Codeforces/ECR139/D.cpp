#include <iostream>
#include <vector>
#include <map>
using namespace std;

using ll = long long;

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
vector<ll> primes = prime_numbers(3200);
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

int solve()
{
  ll x,y;
  scanf("%lld",&x);
  scanf("%lld",&y);
  ll d = y -x;
  if (d == 1){
    cout << -1 << "\n";
    return 0;
  }
  map<ll,ll> dec;
  decomposite(d,dec);
  ll ans = numeric_limits<ll>::max();
  for(auto p:dec){
    ans = min(ans,(x+p.first-1)/p.first * p.first - x);
  }
  cout << ans << "\n";
  return 0;
}
int main()
{
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
