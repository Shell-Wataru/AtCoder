#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int solve()
{
  ll d, m;
  cin >> d >> m;
  ll total = 0;
  for (int i = 0; i <= 30; i++)
  {
    if (i == 0){
      total = 1;
    }else if ((1 << (i+1)) - 1 <= d)
    {
      ll pattens = (1<<i);
      // cout << "i" << pattens << endl;
      total = (pattens + total + (total * pattens % m)) % m;
    }
    else if ((1 << i) - 1 <= d)
    {
      ll patterns = d - (1<<i) + 1;
      // cout << i << "id"  << patterns << endl;
      total = (total + patterns + (total * patterns) % m) % m;
    }
  }
  cout << total << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}