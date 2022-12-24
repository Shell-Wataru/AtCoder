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

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll a,b,d;
  cin >> a >> b >> d;
  cout << fixed << setprecision(12) <<  a * cos(M_PI* d/180) - b*sin(M_PI* d/180) << " " << a * sin(M_PI* d/180) + b*cos(M_PI* d/180) << endl;
  return 0;
}