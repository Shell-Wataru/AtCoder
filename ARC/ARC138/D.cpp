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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

vector<ll> divide(ll N, ll K);

int main()
{
  // 整数の入力
  ll N, K;
  cin >> N >> K;
  if (N == K)
  {
    if (N == 1)
    {
      cout << "Yes\n0 1" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  else if (K % 2 == 1)
  {
    cout << "Yes" << endl;
    vector<vector<ll>> numbers(N+1);
    for (ll i = 0; i < 1ll << N; i++)
    {
      numbers[__builtin_popcountll(i)].push_back(i);
    }
    ll current_index = 0;
    cout << 0 << endl;
    numbers[current_index].pop_back();
    while (true)
    {
      bool found = false;
      for(int i = K;i >= -K;i -= 2){
        if (current_index + i <= N && !numbers[current_index + i].empty())
        {
          current_index += i;
          cout << numbers[current_index].back() << endl;
          numbers[current_index].pop_back();
          break;
          found = true;
        }
      }
      if (!found){
        break;
      }
    }
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}