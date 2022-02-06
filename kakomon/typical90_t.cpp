#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;

ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = my_pow(x, y / 2);
        ll yy = (y_2 * y_2);
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x);
        }
    }
}

int main()
{
  // 整数の入力
  ll a,b,c;
  cin >> a >> b >> c;

  if (a < my_pow(c,b)){
      cout << "Yes" << endl;
  }else{
      cout << "No" << endl;
  }
  return 0;
}