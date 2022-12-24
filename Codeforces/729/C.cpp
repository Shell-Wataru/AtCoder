#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n;
  scanf("%lld", &n);
  ll base = ((n+1)/2)*2;
  vector<ll> bonus_number;
  vector<ll> bonus;
  ll current = 1;
  ll last_point = 0;
  for(int i = 2;i < 10000;i++){
    current *= i/gcd(current,i);
    if (current > n){
      break;
    }
    bonus_number.push_back(current);
    bonus.push_back(i+1 - last_point);
    last_point = i+1;
  }
  for(int i = 0;i < bonus.size();i++){
    base = (base + (n/bonus_number[i]) * bonus[i]) % BASE_NUM;
  }
  cout << base << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
