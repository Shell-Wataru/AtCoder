#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll t;
  ll l = 3;
  ll r = 8;
  ll x = 5;
  cout << l << " " << r << endl;
  for (int i = l;i <= r;i++)
  {
      if (i != l){
          cout << " ";
      }
    cout << (i ^ x);
  }
  cout << endl;
  return 0;
}
