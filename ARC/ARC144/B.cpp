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
#include <climits>

using namespace std;
using ll = long long;

ll answer(vector<ll> &A,ll a,ll b, ll l, ll r){
  if (l+1 == r){
    return l;
  }
  ll center = (l+r)/2;
  ll add_count = 0;
  ll sub_count = 0;
  for(auto aa:A){
    if (aa < center){
      add_count += (center - aa + a- 1)/a;;
    }else{
      sub_count += (aa - center)/b;;
    }
  }
  if (add_count > sub_count){
    return answer(A,a,b,l,center);
  }else{
    return answer(A,a,b,center,r);
  }
}
int main()
{
    ll N,a,b;
    cin >> N >> a >> b;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
      cin >> A[i];
    }
    cout << answer(A,a,b,0,10000000000ll) << endl;
    return 0;
}