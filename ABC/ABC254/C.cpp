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
  ll N,K;
  cin >> N >> K;
  vector<vector<ll>> As(K);
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    As[i%K].push_back(a);
  }
  for(int i = 0;i < K;i++){
    sort(As[i].begin(),As[i].end());
  }
  for(int i = 0;i < N-1;i++){
    if (As[i%K][i/K] > As[(i+1)%K][(i+1)/K]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
   return 0;
}