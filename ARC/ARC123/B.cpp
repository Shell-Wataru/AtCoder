#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  for(int i = 0;i < N;i++){
    cin >> B[i];
  }
  for(int i = 0;i < N;i++){
    cin >> C[i];
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  ll a_index = 0;
  ll b_index = 0;
  ll c_index = 0;
  ll answer = 0;
  while(a_index < N && b_index < N && c_index < N){
    ll new_b_index = upper_bound(B.begin()+b_index,B.end(),A[a_index]) - B.begin();
    if (new_b_index >= N){
      break;
    }
    ll new_c_index = upper_bound(C.begin()+c_index,C.end(),B[new_b_index]) - C.begin();
    if (new_c_index >= N){
      break;
    }
    answer++;
    a_index++;
    b_index = new_b_index+1;
    c_index = new_c_index+1;
  }
  cout << answer << endl;
  return 0;
}