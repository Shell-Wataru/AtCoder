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

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
//   vector<int> all_primes = prime_numbers(1000);
//   all_primes.push_back(1);
  for (size_t i = 0; i < N; i++)
  {
      cin >> A[i];
  }
  sort(A.begin(),A.end());
  set<ll> primes;
  map<ll,ll> counts;
  ll prime_count = 0;
//   primes.push_back(A[0]);
  for(int i = 0; i < N;i++){
      counts[A[i]]++;
      bool is_prime = true;
      for(int j = 1; j <= 1000;j++){
          if (A[i] % j == 0){
              if (primes.find(A[i]/j) != primes.end() || primes.find(j) != primes.end()){
                  is_prime = false;
                  break;
              }
          }
      }
      if (is_prime){
        primes.insert(A[i]);
      }
  }
  ll ans = 0;
  for (auto p:primes)
  {
      if (counts[p] == 1){
          ans++;
      }
  }
  cout << ans << endl;
//   for(auto p: all_primes){
//       cout << p << endl;
//   }
  return 0;
}