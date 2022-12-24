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
vector<int> primes = prime_numbers(3400);
vector<bool> is_prime(5000);

int solve(){
  ll A,B,C,D;
  cin >> A >> B >> C >> D;
  for(int i = A; i <= B;i++){
    bool found = false;
    for(int j = C;j <= D;j++){
      if (is_prime[i+j]){
        found = true;
        break;
      }
    }
    if (!found){
      cout << "Takahashi" << endl;
      return 0;
    }
  }
  cout << "Aoki"  << endl;
  return 0;
}

int main()
{

  for(auto p:primes){
    is_prime[p] = true;
  }
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
    solve();
  // }
  // cout << flush;
  return 0;
}
