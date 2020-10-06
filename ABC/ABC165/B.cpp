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
  ll X;
  ll current = 100;
  ll turn  = 0;
  cin >> X;
  while(current < X){
    current = current + current/100;
    turn++;
  }
  cout << turn << endl;
  return 0;
}