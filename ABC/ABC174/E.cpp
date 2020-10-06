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
#include <set>
using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;

ll bsearch(vector<ll> &A, ll K, ll l, ll r)
{
  if (l + 1 == r)
  {
    return r;
  }
  ll center = (l+r)/2;
  ll cuts = 0;
  for(auto &a:A){
    cuts += (a+center-1)/center - 1;
  }
  if (cuts > K){
    return bsearch(A,K,center,r);
  }else{
    return bsearch(A,K,l,center);
  }
}
int main()
{
  // 整数の入力
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  cout << bsearch(A,K,0,BASE_NUM) << endl;
  return 0;
}
