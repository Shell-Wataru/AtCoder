#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  ll total = 0;
  ll columns = 0;
  for(int i = 0;i < n;i++){
      ll d,c;
      cin >> d >> c;
      columns += c;
      total += d*c;
  }
  cout << (total-1)/9 + columns - 1<< endl;
  return 0;
}
int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}