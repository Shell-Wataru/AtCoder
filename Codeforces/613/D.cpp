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

bool vector_greater(vector<ll> &a, vector<ll> &b)
{
  for (int i = a.size() - 1; i >= 0; i--)
  {
    if (a[i] > b[i])
    {
      return true;
    }
    else if (a[i] < b[i])
    {
      return false;
    }
  }
  return false;
}
vector<ll> minimum(vector<ll> &A, set<ll> &target_rows, ll current_digit)
{
  map<ll, set<ll>> data{{0, set<ll>()}, {1, set<ll>()}};
  for (auto row : target_rows)
  {
    if (A[row] & (1 << current_digit))
    {
      data[1].insert(row);
    }
    else
    {
      data[0].insert(row);
    }
  }
  if (data[0].empty() || data[1].empty())
  {
    if (current_digit == 0)
    {
      return vector<ll>{0};
    }
    else
    {
      vector<ll> sub = minimum(A, target_rows, current_digit - 1);
      sub.push_back(0);
      return sub;
    }
  }
  else
  {
    if (current_digit == 0)
    {
      return vector<ll>{1};
    }
    else
    {
      vector<ll> sub1 = minimum(A, data[0], current_digit - 1);
      vector<ll> sub2 = minimum(A, data[1], current_digit - 1);
      if (!vector_greater(sub1, sub2))
      {
        sub1.push_back(1);
        return sub1;
      }
      else
      {
        sub2.push_back(1);
        return sub2;
      }
    }
  }
}
int main()
{
  ll n;
  cin >> n;
  vector<ll> A;
  set<ll> target_rows;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    A.push_back(a);
    target_rows.insert(i);
  }
  vector<ll> minimum_values = minimum(A, target_rows, 30);
  ll value = 0;
  for(int i = 0;i<= 30;i++){
    value += minimum_values[i]<<i;
  }
  cout << value <<endl;
  return 0;
}