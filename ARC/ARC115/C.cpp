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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

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
vector<int> primes = prime_numbers(200000);
int main()
{
  ll N;
  scanf("%lld",&N);
  vector<ll> A(N+1);
  A[1] = 1;
  ll ans = 1;
  for(int i = 1;i <= N;i++){
    for(auto p:primes){
      if (i * p > N){
        break;
      }
      A[i*p] = A[i]+1;
      ans = max(ans,A[i]+1);
    }
  }
  for(int i = 1;i <= N;i++){
    if (i != 1){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
   return 0;
}