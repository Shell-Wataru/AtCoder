#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

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
vector<int> primes = prime_numbers(1000);

bool is_find(string n,string p){
  ll index = 0;
  for(int i = 0;i < n.size();i++){
    if (n[i] == p[index]){
      index++;
      if (index == p.size()){
        return true;
      }
    }
  }
  return false;
}
int solve()
{
  ll k;
  scanf("%lld", &k);
  string n;
  cin >> n;
  set<ll> prime_sets(primes.begin(),primes.end());
  for(int c = 1; c < 1000;c++){
    if (prime_sets.find(c) == prime_sets.end() && is_find(n,to_string(c))){
      cout << to_string(c).size() << "\n";
      cout << c << "\n";
      break;
    }
  }
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}