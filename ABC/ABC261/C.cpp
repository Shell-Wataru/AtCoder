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
  ll N;
  cin >> N;
  map<string,ll> counts;
  for(int i = 0;i < N;i++){
    string S;
    cin >> S;
    counts[S]++;
    if (counts[S] == 1){
      cout << S <<"\n";
    }else{
      cout << S << "("<< counts[S] - 1<< ")" << "\n";
    }
  }
  cout << flush;
  return 0;
}