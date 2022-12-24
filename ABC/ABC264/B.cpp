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
  ll R,C;
  cin >> R >> C;
  R -= 8;
  C -= 8;
  R = abs(R);
  C = abs(C);
  if (C > R){
    swap(R,C);
  }
  if (R % 2 == 0){
    cout << "white" << endl;
  }else{
    cout << "black" << endl;
  }
  return 0;
}