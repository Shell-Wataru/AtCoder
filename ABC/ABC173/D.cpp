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
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  queue<ll> q;
  for (size_t i = 0; i < N; i++)
  {
      cin >> A[i];
  }
  sort(A.begin(),A.end(),greater<ll>());
  ll ans = 0;
  for(int i = 0 ;i < N;i++){
    if (i == 0){
      q.push(A[i]);
    }else{
      ll a = q.front();
      q.pop();
      ans+= a;
      q.push(A[i]);
      q.push(A[i]);
    }
  }
  cout << ans << endl;
  return 0;
}