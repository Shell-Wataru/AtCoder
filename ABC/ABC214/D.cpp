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

using namespace std;
using ll = long long;

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
vector<int> primes = prime_numbers(100001);
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

int main()
{
  // 整数の入力
  ll N,M;
  cin >> N >> M;
  set<ll> cannot_use;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    map<int,int> dec;
    decomposite(a,dec);
    for(auto p:dec){
      cannot_use.insert(p.first);
    }
  }
  vector<ll> answers;
  for(int i = 1;i <= M;i++){
    bool is_ok = true;
    for(auto no:cannot_use){
      if (i % no == 0){
        is_ok = false;
        break;
      }else if(no > i){
        break;
      }
    }
    if (is_ok){
      answers.push_back(i);
    }
  }
  cout << answers.size() << endl;
  for(int i = 0;i <  answers.size();i++){
    cout << answers[i] << endl;
  }
  return 0;
}
