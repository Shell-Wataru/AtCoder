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
  string S;
  cin >> S;
  bool condition1 = true;
  bool condition2 = true;
  bool condition3 = true;
  ll m = S.length()/2;
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] != S[S.size() - 1 - i])
    {
      condition1 = false;
    }
  }

  for (int i = 0; i < S.size() / 2; i++)
  {
    if (S[i] != S[S.size() / 2 - 1 - i])
    {
      condition2 = false;
    }
  }

  for (int i = 0; i < S.size()/2; i++)
  {
    // cout << i + S.size() / 2 << endl;
    if (S[i + S.size() / 2 + 1] != S[S.size() - 1 - i])
    {
      condition3 = false;
    }
  }
  // cout << condition1 << endl;
  // cout << condition2 << endl;
  // cout << condition3 << endl;
  if (condition1 && condition2 && condition3){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}