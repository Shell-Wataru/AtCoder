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
    // 整数の入力
    string S;
    cin >> S;
    ll ans = 0;
    for(int i = 0;i < 1<<(S.length()-1);i++){
      ll current = 0;
      for(int j = 0;j < S.length();j++){
        current = current * 10 + (S[j] - '0');
        if (i & 1<<j || j == S.length() -1){
          ans += current;
          current = 0;
        }
      }
    }
    cout << ans << endl;
    return 0;
}