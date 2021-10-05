
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
  ll n;
  scanf("%lld",&n);
  deque<ll> q;
  for(int i = 0;i < n;i++){
    ll h;
    scanf("%lld",&h);

    if (h % 2 == 0){
      q.push_back(h);
    }else{
      q.push_front(h);
    }
  }
  bool is_first = true;
  for(auto h:q){
    if (!is_first){
      cout << " ";
    }
    is_first = false;
    cout << h;
  }
  cout << "\n";
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