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

ll pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2);
        ll yy = (y_2 * y_2);
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x);
        }
    }
}

int solve()
{
  ll s, n;
  scanf("%lld", &s);
  scanf("%lld", &n);
  ll one_count = 0;
  priority_queue<ll,vector<ll>,greater<ll>> q;
  ll current_index = 0;
  for(ll i = 1;i <= 10;i++){
    ll amari = (s % pow(10ll,i))/pow(10ll,i-1);
    for(int j = 0;j < amari;j++){
      if (i == 1){
        one_count++;
      }else{
        q.push(pow(10ll,i-1));
      }
      s -= pow(10ll,i-1);
      current_index++;
      if (current_index == n){
        break;
      }
    }
    if (current_index == n){
      break;
    }
  }
  ll search_index = 0;
  while(current_index < n){
    ll base = q.top() / 10;
    q.pop();
    ll remain = base * 10;
    current_index--;
    for(int i = 0; i < 9;i++){
      remain -= base;
      if (base == 1){
        one_count++;
      }else{
        q.push(base);
      }
      current_index++;
      if (current_index == n-1){
        break;
      }
    }
    if (remain == 1){
      one_count++;
    }else{
      q.push(remain);
    }
    current_index++;
  }
  vector<ll> answer;
  for(int i = 0;i < one_count;i++){
    answer.push_back(1);
  }
  while(!q.empty()){
    answer.push_back(q.top());
    q.pop();
  }
  answer[0] += s;
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << answer[i];
  }
  cout << "\n";
    // cout<< total << endl;
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
