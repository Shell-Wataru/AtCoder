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

int main()
{
  ll H, W;
  cin >> H >> W;
  vector<string> G(H);
  vector<vector<bool>> visited(H, vector<bool>(W, false));
  for (int i = 0; i < H; i++)
  {
    cin >> G[i];
  }
  ll current_x = 0;
  ll current_y = 0;
  while (true)
  {
    if (visited[current_x][current_y])
    {
      cout << -1 << endl;
      return 0;
    }
    else
    {
      visited[current_x][current_y] = true;
      ll next_x = current_x;
      ll next_y = current_y;
      if (G[current_x][current_y] == 'U')
      {
        next_x -= 1;
      }
      else if (G[current_x][current_y] == 'D')
      {
        next_x += 1;
      }
      else if (G[current_x][current_y] == 'L')
      {
        next_y -= 1;
      }
      else if (G[current_x][current_y] == 'R')
      {
        next_y += 1;
      }
      if (0 <= next_x && next_x < H && 0 <= next_y && next_y < W){
        current_x = next_x;
        current_y = next_y;
      }else{
        cout << current_x + 1 << " " << current_y + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}