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
int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll p= 2;p*p <= N;p++){
    while(N % p == 0){
      ans++;
      N/= p;
    }
  }

  if (N != 1){
    ans++;
  }
  ll count = 0;
  while(1ll<<count < ans){
    count++;
  }
  // cout << ans << endl;
  cout << count << endl;
  return 0;
}
