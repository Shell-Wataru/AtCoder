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

vector<int> prime_numbers(int n)
{
  if (n <= 1)
  {
    return vector<int>(0);
  }
  vector<int> ans = {2};
  for (int i = 3; i <= n; i++)
  {
    bool is_prime = true;
    for (int j = 0; ans[j] * ans[j] <= i; j++)
    {
      if (i % ans[j] == 0)
      {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
    {
      ans.push_back(i);
    }
  }
  return ans;
}
vector<int> primes = prime_numbers(10001);
void decomposite(int N, map<int, int> &factors, int p_index = 0)
{
  if (N == 1)
  {
    return;
  }

  while (primes[p_index] * primes[p_index] <= N)
  {
    if (N % primes[p_index] == 0)
    {
      factors[primes[p_index]] += 1;
      decomposite(N / primes[p_index], factors, p_index);
      return;
    }
    else
    {
      p_index++;
    }
  }
  factors[N] += 1;
}

int main()
{
  // cout << primes.size() << endl;
  // 整数の入力
  vector<ll> base = {
    2*3,
    3*5,
    2*5
  };
  // for(int i = 0;i < 7;i++){
  //   cout << base[i] << endl;
  // }
  ll N;
  cin >> N;
  set<ll> used;
  for(int i = 0;i < min(3ll,N);i++){
    cout << base[i] << "\n";
    used.insert(base[i]);
  }
  N -= min(3ll,N);
  vector<ll> factors;
  for(int i = 2;i<10000;i++){
    factors.push_back(i);
  }
  // cout << factors.size() << endl;

  for(int i = 0;i < 3;i++){
    ll prime_i = 0;
    while(N > 0 && base[i] * factors[prime_i] <= 10000){
      if (used.find(base[i] * factors[prime_i]) == used.end()){
        N--;
        cout << base[i] * factors[prime_i] << "\n";
        used.insert(base[i] * factors[prime_i]);
      }
      prime_i++;
    }
  }
  cout << flush;
  // ll a = 0;
  // for(auto u:used){
  //   a = gcd(a,u);
  // }
  // cout << a << endl;
  // cout << N << endl;
  return 0;
}