

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
    ll H,M;
    cin >> H >> M;
    for(int i = 0;i < 24*60;i++){
      ll h = (H + (M+i)/60)%24;
      ll m = (M + i)%60;
      ll h1 = h/10;
      ll h2 = h%10;
      ll m1 = m/10;
      ll m2 = m%10;
      ll new_h = h1*10 + m1;
      ll new_m = h2*10 + m2;
      // cout << h << " " << m << endl;
      if (0 <= new_h  && new_h < 24 && 0 <= new_m && new_m < 60){
        cout << h << " " << m << endl;
        return 0;
      }
    }
    return 0;
}