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


const long long BASE_NUM = 1000000007;
ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else{
        ll y_2 =my_pow(x,y/2);
        ll yy = y_2 * y_2;
        if (y % 2 == 0){
            return yy;
        }else{
            return yy * x;
        }
    }
}

int main()
{
  ll N;
  cin >> N;
  ll ans = 0;
  for(int i = 0;i < 6;i++){
    if (my_pow(10,3*(i+1)) <= N){
      ans += i * (my_pow(10,3*(i+1)) - my_pow(10,3*i));
    }else{
      ans += i * (N - my_pow(10,3*i) + 1);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}