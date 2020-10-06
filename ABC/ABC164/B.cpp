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

int main()
{
  // 整数の入力
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  ll turn = 0;
  while (true)
  {
    if (turn % 2 == 0)
    {
      C -= B;
    }
    else
    {
      A -= D;
    }
    if (A <= 0 || C <= 0)
    {
      break;
    }
    turn++;
  }
  // cout << A << endl;
  // cout << C << endl;
  if (C <= 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}