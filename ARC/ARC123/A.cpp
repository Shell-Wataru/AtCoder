#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll A, B, C;
  cin >> A >> B >> C;
  if (A <= B && B <= C)
  {
    ll l1 = B - A;
    ll l2 = C - B;
    if (l2 > l1)
    {
      cout << (l2 - l1 + 1) / 2 + (l2 - l1) % 2 << endl;
    }
    else
    {
      cout << l1 - l2 << endl;
    }
  }
  else if (B <= C && C <= A)
  {
    ll l1 = C - B;
    ll l2 = A - C;
    cout << l1 + (l2 + 1) / 2 + l2 % 2 << endl;
  }
  else if (C <= A && A <= B)
  {
    ll l1 = B - A;
    ll l2 = B - C;
    cout << l1 + l2 << endl;
  }
  else if (C <= B && B <= A)
  {
    ll l1 = B - C;
    ll l2 = A - B;
    if (l2 > l1)
    {
      cout << (l2 - l1 + 1) / 2 + (l2 - l1) % 2 << endl;
    }
    else
    {
      cout << l1 - l2 << endl;
    }
  }
  else if (B <= A && A <= C)
  {
    ll l1 = A - B;
    ll l2 = C - A;
    cout << l1 + (l2 + 1) / 2 + l2 % 2 << endl;
  }
  else if (A <= C && C <= B)
  {
    ll l1 = B - C;
    ll l2 = B - A;
    cout << l1 + l2 << endl;
  }
  return 0;
}