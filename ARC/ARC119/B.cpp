#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N;
  string S,T;
  cin >> N >> S >> T;
  vector<ll> s_zeros;
  vector<ll> t_zeros;
  for(int i = 0;i < N;i++){
    if (S[i] == '0'){
      s_zeros.push_back(i);
    }
    if (T[i] == '0'){
      t_zeros.push_back(i);
    }
  }
  if (s_zeros.size() != t_zeros.size()){
    cout << -1 << endl;
  }else{
    ll ans = 0;
    for(int i =0;i< s_zeros.size();i++){
      if (s_zeros[i] != t_zeros[i]){
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}