#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  // 整数の入力
  ll H, W;
  cin >> H >> W;
  vector<string> G(H);
  vector<vector<bool>> FirstWin(H, vector<bool>(W, false));
  for (size_t i = 0; i < H; i++)
  {
    cin >> G[i];
  }
  //     for (size_t i = 0; i < H; i++)
  // {
  //   for (size_t j = 0; j < W; j++)
  //   {
  //     if (G[i][j] == 'o'){
  //       start_x = i;
  //       start_y = j;
  //     }
  //   }
  // }
  for (ll i = H - 1; i >= 0; i--)
  {
    for (ll j = W - 1; j >= 0; j--)
    {
      if (G[i][j] == '#')
      {
        continue;
      }
      bool first_win = false;
      if (j + 1 < W && G[i][j + 1] != '#' && !FirstWin[i][j + 1])
      {
        first_win = true;
      }
      if (i + 1 < H && G[i + 1][j] != '#' && !FirstWin[i + 1][j])
      {
        first_win = true;
      }
      if (i + 1 < H && j + 1 < W && G[i + 1][j+1] != '#' && !FirstWin[i + 1][j+1])
      {
        first_win = true;
      }
      FirstWin[i][j] = first_win;
    }
  }
  // for(int i = 0;i < H;i++){
  //   for(int j = 0;j < W;j++){
  //     if (G[i][j] == '#'){
  //       cout << "#";
  //     }else if(FirstWin[i][j]){
  //       cout << 1;
  //     }else{
  //       cout << 0;
  //     }
  //   }
  //   cout << endl;
  // }
  if (FirstWin[0][0])
  {
    cout << "First" << endl;
  }
  else
  {
    cout << "Second" << endl;
  }
  return 0;
}