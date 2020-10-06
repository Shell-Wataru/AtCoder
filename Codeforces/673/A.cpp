#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> A(n);
  ll min_pile_candies = numeric_limits<ll>::max();
  ll min_pile_index = -1;
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
    if (A[i] < min_pile_candies){
      min_pile_candies = A[i];
      min_pile_index = i;
    }
  }

  ll total = 0;
  for (size_t i = 0; i < n; i++)
  {
    if(i == min_pile_index){
      continue;
    }
    total += (k - A[i])/min_pile_candies;
  }
  cout << total << endl;
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
  return 0;
}