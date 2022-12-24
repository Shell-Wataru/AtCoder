#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;

ll f(vector<ll> &A,ll X,ll maximum,ll min_add){
  ll real_minimum = numeric_limits<ll>::max();
  ll real_maximum = 0;
  for(auto a:A){
    ll l = a;
    ll r = a;
    ll add_count = 0;
    while(2*l <= maximum || add_count < min_add){
      add_count++;
      l = 2*l;
      r = 2* r + X;
    }
    if (l > maximum){
      return numeric_limits<ll>::max();
    }
    real_minimum = min(real_minimum,min(maximum,r));
    real_maximum = max(real_maximum,min(maximum,r));
  }
  return real_maximum - real_minimum;
}

ll three_search(ll l, ll r, vector<ll> &A,ll X,ll min_add)
{
  cout << l << "~" << r << endl;
  if (l + 2 == r)
  {
    ll t1 = l;
    ll t2 = l + 1;
    ll t3 = l + 2;
    ll t1_value = f(A,X,t1,min_add);
    ll t2_value = f(A,X,t2,min_add);
    ll t3_value = f(A,X,t3,min_add);
    if (t1_value <= t2_value && t1_value <= t3_value)
    {
      return t1;
    }
    else if (t2_value <= t3_value && t2_value <= t1_value)
    {
      return t2;
    }
    else
    {
      return t3;
    }
  }
  else
  {
    ll t1 = (2 * l + r) / 3;
    ll t2 = (l + 2 * r) / 3;
    ll t1_value = f(A,X,t1,min_add);
    ll t2_value = f(A,X,t2,min_add);
    if (t1_value <= t2_value)
    {
      return three_search(l, t2, A,X,min_add);
    }
    else
    {
      return three_search(t1, r, A,X,min_add);
    }
  }
}

int main()
{
  // 整数の入力
  ll N,X;
  cin >> N >> X;
  vector<ll> A(N);
  ll l_maximum = 0;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    q.push({A[i],A[i]});
    l_maximum = max(l_maximum,A[i]);
  }
  ll ans = numeric_limits<ll>::max();
  ans = min(ans,max(l_maximum - q.top().first,0ll));
  while(2*q.top().first + X < 1ll<<60){
    // cout << q.top().first << endl;
    auto p = q.top();
    q.pop();
    l_maximum = max(l_maximum,2*p.second);
    q.push({2*p.first+X,2*p.second});
    ans = min(ans,max(l_maximum - q.top().first,0ll));
  }
  cout << ans << endl;
  return 0;
}