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
  vector<pair<pair<ll,ll>,pair<ll,ll>>> A(N);
  for(int i = 0;i < N;i++){
      ll t,l,r;
      cin >> t >> l >> r;
      if ( t == 1){
        A[i].first = {l,0};
        A[i].second = {r,1};
      }else if (t == 2){
        A[i].first = {l,0};
        A[i].second = {r,0};
      }else if(t == 3){
        A[i].first = {l,1};
        A[i].second = {r,1};
      }else{
        A[i].first = {l,1};
        A[i].second = {r,0};
      }

    //   cout << l << "," << r << endl;
  }
  ll ans = 0;
  for(int i = 0;i < N;i++){
      for(int j = i+1;j < N;j++){
          if (max(A[i].first,A[j].first) < min(A[i].second,A[j].second) ){
              ans++;
          }
      }
  }
  cout << ans << endl;
  return 0;
}