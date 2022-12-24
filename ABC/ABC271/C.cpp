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

ll answer(vector<ll> &a,ll l,ll r){
  if (l+1 == r){
    return l;
  }
  ll center = (l+r)/2;
  ll initial_free = 0;
  vector<ll> counts(center+1);
  for(auto aa:a){
    if (aa > center){
      initial_free++;
    }else if (counts[aa] == 0){
      counts[aa]++;
    }else{
      initial_free++;
    }
  }
  for(int i = 1;i <= center;i++){
    if (counts[i] == 1){

    }else{
      initial_free -= 2;
    }
  }
  if (initial_free >= 0){
    return answer(a,center,r);
  }else{
    return answer(a,l,center);
  }
}
int main()
{
  ll N;
  cin >> N;
  vector<ll>a(N);
  for(int i = 0;i < N;i++){
    cin >> a[i];
  }

  sort(a.begin(),a.end());
  ll current = 1;
  ll free = 0;
  cout << answer(a,0,N+1) << endl;
  return 0;
}