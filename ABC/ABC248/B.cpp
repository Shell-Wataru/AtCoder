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
  ll A,B,K;
  cin >> A >> B >> K;
  ll ans = 0;
  while(A < B){
    ans++;
    A *= K;
  }
  cout <<  ans << endl;
  return 0;
}