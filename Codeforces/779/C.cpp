#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

vector<ll> total_xors(1ll<<17);

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  vector<ll> c(n);
  ll start_index = -1;
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&c[i]);
  }
  for (size_t i = 0; i < n; i++)
  {
    if (c[i] == 1){
      start_index =i;
    }
  }
  if (start_index == -1){
    cout << "No\n";
    return 0;
  }
  ll last = 1;
  for(int i = 1;i < n;i++){
    if (1 < c[(i+start_index)% n] &&  c[(i+start_index) % n] <= last + 1){
      last =  c[(i+start_index) % n];
    }else{
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}

int main()
{
  for(int i = 1;i < 1ll<<17;i++ ){
    total_xors[i] = i ^ total_xors[i-1];
  }
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
