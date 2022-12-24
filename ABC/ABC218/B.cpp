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
  vector<ll> A(26);
  string S;
  for(int i = 0;i < 26;i++){
    ll a;
    cin >> a;
    a--;
    S += 'a' + a;
  }
  cout <<  S << endl;
  return 0;
}