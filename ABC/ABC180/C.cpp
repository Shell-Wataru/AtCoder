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

int main()
{
  ll N;
  cin >> N;
  vector<ll> ans;
  for (size_t i = 1; i * i <= N; i++)
  {
    if (N % i == 0){
      ans.push_back(i);
      if (i * i != N){
        ans.push_back(N/i);
      }
    }
  }
  sort(ans.begin(),ans.end());
  for(auto n: ans){
    cout << n << endl;
  }

  return 0;
}