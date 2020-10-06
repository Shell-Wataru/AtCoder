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
using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
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

void decomposite(int N, map<int,int> & factors, vector<int> &primes,int p_index = 0){
    if (N == 1){
        return;
    }

    while (primes[p_index] * primes[p_index] <= N ) {
        if (N % primes[p_index] == 0) {
            factors[primes[p_index]] += 1;
            decomposite(N/primes[p_index],factors,primes,p_index);
            return;
        } else {
            p_index++;
        }
    }
    factors[N] += 1;
}

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  bool pairwise_co = true;
  ll all_gcd = 0;
  set<ll> used_primes;
  vector<int> primes = prime_numbers(2001);

  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
    map<int,int> factors;
    decomposite(A[i],factors,primes);
    all_gcd = gcd(all_gcd,A[i]);

    for(auto &p:factors){
      if (used_primes.find(p.first) != used_primes.end()){
        pairwise_co = false;
      }
      used_primes.insert(p.first);
    }

  }

  if (pairwise_co){
    cout << "pairwise coprime" << endl;
  }else if(all_gcd == 1){
    cout << "setwise coprime" << endl;
  }else{
    cout << "not coprime" << endl;
  }
  return 0;
}
