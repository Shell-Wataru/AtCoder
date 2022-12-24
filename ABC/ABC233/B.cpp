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
  ll L,R;
  cin >> L >> R;
  string S;
  cin >> S;
  L--;
  reverse(S.begin()+L,S.begin()+R);
  cout << S<< endl;
  return 0;
}