
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  scanf("%lld",&n);
  scanf("%lld",&k);
  deque<ll> q(n);
  iota(q.begin(),q.end(),1);
  if (2 * k < n){
    for(int i = 0;i < k;i++){
      cout << q.front() << " ";
      cout << q.back() << " ";
      q.pop_front();
      q.pop_back();
    }
    while(!q.empty()){
      if (q.size() == 1){
        cout << q.front() << "\n";
        q.pop_front();
      }else{
        cout << q.front() << " ";
        q.pop_front();
      }
    }
  }else{
    cout << -1 << "\n";
  }
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}