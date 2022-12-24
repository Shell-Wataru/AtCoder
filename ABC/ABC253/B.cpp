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
  ll H,W;
  cin >> H >> W;
  vector<string> G(H);
  for(int i = 0;i < H;i++){
    cin >> G[i];
  }
  ll x1,y1,x2,y2;
  bool x1_found =false;
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      if (G[i][j] == 'o'){
        if (!x1_found){
          x1 = i;
          y1 = j;
          x1_found = true;
        }else{
          x2 = i;
          y2 = j;
          break;
        }
      }
    }
  }
  cout << abs(x1-x2) + abs(y1-y2) << endl;
  return 0;
}