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
ll BASE_NUM = 1000000007;

int main()
{
  ll H,W,K;
  cin >> H >> W >> K;
  vector<string> G(H);
  for (size_t i = 0; i < H; i++)
  {
      cin >> G[i];
  }
  ll ans = 0;
  for (size_t i = 0; i < (1<<H); i++)
  {
    for (size_t j = 0; j < (1<<W); j++)
    {
      vector<string> GG(G);
      for(int ii = 0;ii < H;ii++){
        if (i & (1<<ii)){
          for(int k = 0;k < W;k++){
            GG[ii][k] = '.';
          }
        }
      }

      for(int jj = 0;jj < W;jj++){
        if (j & (1<<jj)){
          for(int k = 0;k < H;k++){
            GG[k][jj] = '.';
          }
        }
      }
      ll total = 0;
      for(int k = 0;k < H;k++){
        for (size_t l = 0; l < W; l++)
        {
          if (GG[k][l] == '#'){
            total++;
          }
        }
      }
      if (total == K){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}