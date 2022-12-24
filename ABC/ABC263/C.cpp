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

int dfs(vector<ll> &a,ll N,ll M){
  if (a.size() == N+1){
    for(int i = 1;i < N+1;i++){
      if (i!=1){
        cout << " ";
      }
      cout << a[i];
    }
    cout << "\n";
  }else{
    for(int i = a.back()+1;i<= M;i++){
      a.push_back(i);
      dfs(a,N,M);
      a.pop_back();
    }
  }
  return 0;
}
int main()
{
  ll N,M;
  cin >> N >> M;
  vector<ll> a;
  a.push_back(0);
  dfs(a,N,M);
  cout << flush;
  return 0;
}