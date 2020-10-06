#define _USE_MATH_DEFINES
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
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000000;

ll my_pow(ll x,ll y,bool &greater){
    if (y == 0){
        return 1LL;
    }else{
        ll y_2 =my_pow(x,y/2, greater);
        ll yy = (y_2 * y_2);
        if (yy > BASE_NUM){
          greater = true;
        }
        if (y % 2 == 0){
            return yy;
        }else{
            if (yy * x > BASE_NUM){
              greater = true;
            }
            return yy * x;
        }
    }
}


int main()
{
  // 整数の入力

  ll A, R, N;
  cin >> A >> R >> N;
  bool greater = false;
  ll times = my_pow(R,N - 1,greater);
  ll ans = A * times;
  if (!greater && ans > BASE_NUM){
    greater = true;
  }
  if (greater){
    cout << "large" << endl;
  }else{
    cout << ans << endl;
  }
}