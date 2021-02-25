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
  ll X,Y,A,B;
  cin >> X >> Y >> A >> B;
  ll times = 0;
  while(X <=  (X + B)/A && X <= (Y - 1)/A){
    times++;
    X = A*X;
  }
  times += (Y - X - 1)/B;
  cout << times << endl;
  return 0;
}
