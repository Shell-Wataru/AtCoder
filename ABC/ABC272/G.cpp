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
#include <set>
#include <atcoder/mincostflow>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

vector<ll> prime_numbers(int n)
{
  if (n <= 1)
  {
    return vector<ll>(0);
  }
  vector<ll> ans = {2};
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
vector<ll> primes = prime_numbers(100000);
void decomposite(ll N, map<ll, ll> &factors, int p_index = 0)
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
  ll N;
  cin >> N;
  vector<ll> A(N);

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  std::random_device rnd;                        // 非決定的な乱数生成器でシード生成機を生成
  std::mt19937 mt(rnd());                        //  メルセンヌツイスターの32ビット版、引数は初期シード
  std::uniform_int_distribution<> rand100(0, N-1); // [0, 99] 範囲の一様乱数
  for (int i = 0; i < 30; i++)
  {
    unordered_map<ll,ll> counts;
    ll wildcard = 1;
    ll index = rand100(mt);
    // cout << index << endl;
    for (int j = 0; j < N; j++)
    {
      ll x = abs(A[index] - A[j]);
      if (x == 1){
        continue;
      }else if (x == 0){
        // wildcard++;
        continue;
      }
      map<ll,ll> dec;
      decomposite(x,dec);
      for(auto p:dec){
        counts[p.first]++;
        if (p.first == 2 && p.second >= 2 ){
          counts[4]++;
          if ( (counts[4]+wildcard)*2> N  && 4 >= 3){
            cout << 4 << endl;
            return 0;
          }
        }
        if ( (counts[p.first]+wildcard)*2> N  && p.first >= 3){
          cout << p.first << endl;
          return 0;
        }
      }
    }
    if (wildcard*2 > N){
      cout << 3 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
