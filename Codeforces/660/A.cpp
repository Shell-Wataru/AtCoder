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
  ll n;
  cin >> n;
  ll min_nearly_positive_number_sum =  6 + 10 + 14;
  if (n > min_nearly_positive_number_sum){
    cout << "YES" << endl;
    ll remain = n -min_nearly_positive_number_sum;
    if (remain == 6 || remain == 10 || remain == 14){
      cout << 6 << " " << 10 << " " << 15 << " " << remain - 1 << endl;
    }else{
      cout << 6 << " " << 10 << " " << 14 << " " << remain << endl;

    }
  }else{
    cout << "NO" << endl;
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
  return 0;
}