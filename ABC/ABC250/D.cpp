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
#include <stack>

using namespace std;
using ll = long long;

vector<ll> prime_numbers(int n){
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
vector<ll> primes = prime_numbers(1100000);

int solve()
{
  ll N;
  cin >> N;
  ll ans = 0;
  for(int i = 0;i < primes.size();i++){
    for(int j = 0;j < i;j++){
      if ( primes[i] * primes[i] *  primes[i] * primes[j] <= N && primes[i] * primes[i] <= N/(primes[j]*primes[i])  + 1){
        // cout << primes[i] << "," << primes[j] << endl;
        // cout << primes[i] * primes[i]  << endl;
        // cout << N/(primes[i] * primes[j])  << endl;
        ans++;
      }else{
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
