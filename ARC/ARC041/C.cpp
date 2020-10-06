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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;

struct rabbit
{
  ll index, weight;
  char direction;
};
int main()
{
  ll N, L;
  cin >> N >> L;
  vector<rabbit> rabbits;
  ll ans = 0;
  for (size_t i = 0; i < N; i++)
  {
    ll index;
    char direction;
    cin >> index >> direction;
    if (rabbits.empty())
    {
      rabbits.push_back({index, 1, direction});
    }
    else
    {
      if (rabbits.back().direction == direction)
      {
        if (direction == 'L')
        {
          ans += index - rabbits.back().index - rabbits.back().weight;
          rabbits.back().weight++;
        }
        else
        {
          ans += rabbits.back().weight * (index - rabbits.back().index - 1);
          rabbits.back().weight++;
          rabbits.back().index = index;
        }
      }
      else
      {
        rabbits.push_back({index, 1, direction});
      }
    }
  }
  for(int i = 0;i < rabbits.size()-1;i++){
    if (rabbits[i].direction == 'R' && rabbits[i+1].direction == 'L'){
      ans += max(rabbits[i].weight,rabbits[i+1].weight) * (rabbits[i+1].index - rabbits[i].index - 1);
    }
  }
  if (rabbits[0].direction == 'L'){
    ans+= (rabbits[0].index - 1)*  rabbits[0].weight;
  }
  if (rabbits.back().direction == 'R'){
    ans+= (L - rabbits.back().index)*  rabbits.back().weight;
  }
  cout << ans << endl;
  return 0;
}